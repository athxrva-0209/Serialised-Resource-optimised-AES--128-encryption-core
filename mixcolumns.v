// module mixcolumns (
//     input  wire        clk,
//     input  wire        rst_n,
//     input  wire        start,
//     input  wire [31:0] col_in,
//     output reg  [31:0] col_out,
//     output reg         done
// );

//     reg [1:0] count;
//     reg       busy;
//     reg [31:0] col_reg;

//     // GF(2^8) multiply by 2 (xtime)
//     function [7:0] xtime;
//         input [7:0] b;
//         begin
//             xtime = (b[7]) ? ((b << 1) ^ 8'h1b) : (b << 1);
//         end
//     endfunction

//     // 1. DATA SELECTION: 
//     // Use the fresh input 'col_in' during the 'start' cycle, 
//     // otherwise use the latched 'col_reg'.
//     wire [31:0] active_col = (start && !busy) ? col_in : col_reg;

//     wire [7:0] s0 = active_col[31:24];
//     wire [7:0] s1 = active_col[23:16];
//     wire [7:0] s2 = active_col[15:8];
//     wire [7:0] s3 = active_col[7:0];

//     // 2. GALOIS FIELD PRECOMPUTATION
//     wire [7:0] s0_x2 = xtime(s0), s0_x3 = s0_x2 ^ s0;
//     wire [7:0] s1_x2 = xtime(s1), s1_x3 = s1_x2 ^ s1;
//     wire [7:0] s2_x2 = xtime(s2), s2_x3 = s2_x2 ^ s2;
//     wire [7:0] s3_x2 = xtime(s3), s3_x3 = s3_x2 ^ s3;

//     // 3. COMBINATIONAL ROW LOGIC
//     reg [7:0] row_result;
//     always @(*) begin
//         case (count)
//             2'b00: row_result = s0_x2 ^ s1_x3 ^ s2    ^ s3;    // Row 0
//             2'b01: row_result = s0    ^ s1_x2 ^ s2_x3 ^ s3;    // Row 1
//             2'b10: row_result = s0    ^ s1    ^ s2_x2 ^ s3_x3; // Row 2
//             2'b11: row_result = s0_x3 ^ s1    ^ s2    ^ s3_x2; // Row 3
//             default: row_result = 8'h00;
//         endcase
//     end

//     // 4. SEQUENTIAL CONTROL
//     always @(posedge clk or negedge rst_n) begin
//         if (!rst_n) begin
//             count   <= 2'b00;
//             col_out <= 32'h0;
//             done    <= 1'b0;
//             busy    <= 1'b1; // Wait for first start
//             busy    <= 1'b0;
//             col_reg <= 32'h0;
//         end 
//         else if (start && !busy) begin
//             col_reg <= col_in;
//             count   <= 2'b01; // Start counting next cycle
//             busy    <= 1'b1;
//             done    <= 1'b0;
//             // Capture the first row result immediately
//             col_out[31:24] <= row_result; 
//         end 
//         else if (busy) begin
//             // Store subsequent results
//             case (count)
//                 2'b01: col_out[23:16] <= row_result;
//                 2'b10: col_out[15:8]  <= row_result;
//                 2'b11: col_out[7:0]   <= row_result;
//                 default : col_out[7:0] <= 0;
//             endcase

//             if (count == 2'b11) begin
//                 busy <= 1'b0;
//                 done <= 1'b1;
//                 count <= 2'b00;
//             end else begin
//                 count <= count + 1;
//             end
//         end 
//         else begin
//             done <= 1'b0;
//         end
//     end

// endmodule

module mixcolumns (
    input  wire         clk,
    input  wire         rst_n,
    input  wire         start,
    input  wire [127:0] state_in,
    output reg  [127:0] state_out,
    output reg          done
);

    reg [1:0] col_count;
    reg       busy;
    reg [127:0] internal_state;

    // GF(2^8) multiply by 2 (xtime)
    function [7:0] xtime;
        input [7:0] b;
        begin
            xtime = (b[7]) ? ((b << 1) ^ 8'h1b) : (b << 1);
        end
    endfunction

    // 1. Column Selection Logic
    reg [31:0] current_col;
    always @(*) begin
        case (col_count)
            2'd0: current_col = internal_state[127:96];
            2'd1: current_col = internal_state[95:64];
            2'd2: current_col = internal_state[63:32];
            2'd3: current_col = internal_state[31:0];
            default: current_col = 32'd0;
        endcase
    end

    wire [7:0] s0 = current_col[31:24];
    wire [7:0] s1 = current_col[23:16];
    wire [7:0] s2 = current_col[15:8];
    wire [7:0] s3 = current_col[7:0];

    // 2. GF(2^8) Precomputation
    wire [7:0] s0_x2 = xtime(s0), s0_x3 = s0_x2 ^ s0;
    wire [7:0] s1_x2 = xtime(s1), s1_x3 = s1_x2 ^ s1;
    wire [7:0] s2_x2 = xtime(s2), s2_x3 = s2_x2 ^ s2;
    wire [7:0] s3_x2 = xtime(s3), s3_x3 = s3_x2 ^ s3;

    // 3. Sequential Iteration Logic
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            col_count      <= 2'd0;
            state_out      <= 128'd0;
            done           <= 1'b0;
            busy           <= 1'b0;
            internal_state <= 128'd0;
        end else if (start && !busy) begin
            internal_state <= state_in;
            busy           <= 1'b1;
            col_count      <= 2'd0;
            done           <= 1'b0;
        end else if (busy) begin
            // Store computed column into the result register
            case (col_count)
                2'd0: state_out[127:96] <= {s0_x2^s1_x3^s2^s3, s0^s1_x2^s2_x3^s3, s0^s1^s2_x2^s3_x3, s0_x3^s1^s2^s3_x2};
                2'd1: state_out[95:64]  <= {s0_x2^s1_x3^s2^s3, s0^s1_x2^s2_x3^s3, s0^s1^s2_x2^s3_x3, s0_x3^s1^s2^s3_x2};
                2'd2: state_out[63:32]  <= {s0_x2^s1_x3^s2^s3, s0^s1_x2^s2_x3^s3, s0^s1^s2_x2^s3_x3, s0_x3^s1^s2^s3_x2};
                2'd3: state_out[31:0]   <= {s0_x2^s1_x3^s2^s3, s0^s1_x2^s2_x3^s3, s0^s1^s2_x2^s3_x3, s0_x3^s1^s2^s3_x2};
            endcase

            if (col_count == 2'd3) begin
                busy <= 1'b0;
                done <= 1'b1;
            end else begin
                col_count <= col_count + 1'b1;
            end
        end else begin
            done <= 1'b0;
        end
    end
endmodule