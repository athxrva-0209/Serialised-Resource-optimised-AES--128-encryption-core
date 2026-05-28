module subbytes(
    input              clk,
    input              reset,
    input              start,
    input      [127:0] state_in,
    output reg [127:0] state_out,
    output reg         done
);

    reg  [3:0]  counter;
    reg  [7:0]  sbox_in;
    wire [7:0]  sbox_out;
    reg         busy;

    sbox my_sbox (
        .a(sbox_in),
        .c(sbox_out)
    );

    // Explicit byte mux — no variable part-select ambiguity
    always @(*) begin
        case (counter)
            4'd0:  sbox_in = state_in[127:120];
            4'd1:  sbox_in = state_in[119:112];
            4'd2:  sbox_in = state_in[111:104];
            4'd3:  sbox_in = state_in[103: 96];
            4'd4:  sbox_in = state_in[ 95: 88];
            4'd5:  sbox_in = state_in[ 87: 80];
            4'd6:  sbox_in = state_in[ 79: 72];
            4'd7:  sbox_in = state_in[ 71: 64];
            4'd8:  sbox_in = state_in[ 63: 56];
            4'd9:  sbox_in = state_in[ 55: 48];
            4'd10: sbox_in = state_in[ 47: 40];
            4'd11: sbox_in = state_in[ 39: 32];
            4'd12: sbox_in = state_in[ 31: 24];
            4'd13: sbox_in = state_in[ 23: 16];
            4'd14: sbox_in = state_in[ 15:  8];
            4'd15: sbox_in = state_in[  7:  0];
            default: sbox_in = 8'd0;
        endcase
    end

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            counter   <= 4'd0;
            state_out <= 128'd0;
            done      <= 1'b0;
            busy      <= 1'b0;
        end

        else if (start && !busy) begin
            counter   <= 4'd0;
            done      <= 1'b0;
            busy      <= 1'b1;
        end

        else if (busy) begin
            // Write-back using explicit case — same positions as read
            case (counter)
                4'd0:  state_out[127:120] <= sbox_out;
                4'd1:  state_out[119:112] <= sbox_out;
                4'd2:  state_out[111:104] <= sbox_out;
                4'd3:  state_out[103: 96] <= sbox_out;
                4'd4:  state_out[ 95: 88] <= sbox_out;
                4'd5:  state_out[ 87: 80] <= sbox_out;
                4'd6:  state_out[ 79: 72] <= sbox_out;
                4'd7:  state_out[ 71: 64] <= sbox_out;
                4'd8:  state_out[ 63: 56] <= sbox_out;
                4'd9:  state_out[ 55: 48] <= sbox_out;
                4'd10: state_out[ 47: 40] <= sbox_out;
                4'd11: state_out[ 39: 32] <= sbox_out;
                4'd12: state_out[ 31: 24] <= sbox_out;
                4'd13: state_out[ 23: 16] <= sbox_out;
                4'd14: state_out[ 15:  8] <= sbox_out;
                4'd15: state_out[  7:  0] <= sbox_out;
                default: ;
            endcase

            if (counter == 4'd15) begin
                done <= 1'b1;
                busy <= 1'b0;
            end else begin
                counter <= counter + 1'b1;
            end
        end

        else begin
            done <= 1'b0;
        end
    end

endmodule