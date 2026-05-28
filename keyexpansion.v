module keyexpansion (
    input  wire         clk,
    input  wire         rst_n,
    input  wire         load_key,    // High to load the initial Cipher Key
    input  wire         update_key,  // High to calculate the NEXT round key
    input  wire [127:0] key_in,      // Initial 128-bit key
    input  wire [3:0]   round_in,    // The round index for the NEXT key (1-10)
    output reg  [127:0] round_key    // The key to be used for AddRoundKey
);

    // --- Rcon Look-up Table ---
    function [7:0] get_rcon(input [3:0] r);
        case(r)
            4'd1:  get_rcon = 8'h01; 4'd2:  get_rcon = 8'h02;
            4'd3:  get_rcon = 8'h04; 4'd4:  get_rcon = 8'h08;
            4'd5:  get_rcon = 8'h10; 4'd6:  get_rcon = 8'h20;
            4'd7:  get_rcon = 8'h40; 4'd8:  get_rcon = 8'h80;
            4'd9:  get_rcon = 8'h1b; 4'd10: get_rcon = 8'h36;
            default: get_rcon = 8'h00;
        endcase
    endfunction

    // --- S-Box Instantiations ---
    // RotWord: [b0 b1 b2 b3] -> [b1 b2 b3 b0]
    wire [31:0] last_word = round_key[31:0];
    wire [7:0] sub_out0, sub_out1, sub_out2, sub_out3;

    // Instantiate 4 S-Boxes with your specific ports (a and c)
    // We pass the rotated bytes of the last word (w3)
    sbox sbox_inst0 (.a(last_word[23:16]), .c(sub_out0)); // Byte 1
    sbox sbox_inst1 (.a(last_word[15:8]),  .c(sub_out1)); // Byte 2
    sbox sbox_inst2 (.a(last_word[7:0]),   .c(sub_out2)); // Byte 3
    sbox sbox_inst3 (.a(last_word[31:24]), .c(sub_out3)); // Byte 0

    // --- Core g-function logic ---
    wire [31:0] g_out;
    assign g_out[31:24] = sub_out0 ^ get_rcon(round_in);
    assign g_out[23:16] = sub_out1;
    assign g_out[15:8]  = sub_out2;
    assign g_out[7:0]   = sub_out3;

    // --- Generate Next Words (XOR Chain) ---
    wire [31:0] w0_next = round_key[127:96] ^ g_out;
    wire [31:0] w1_next = round_key[95:64]  ^ w0_next;
    wire [31:0] w2_next = round_key[63:32]  ^ w1_next;
    wire [31:0] w3_next = round_key[31:0]   ^ w2_next;

    // --- Key Register ---
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            round_key <= 128'h0;
        end else if (load_key) begin
            round_key <= key_in; // Initial Round 0 Key
        end else if (update_key) begin
            // The logic (w0_next, etc) uses the current round_key 
            // and the current round_in to find the NEXT key.
            round_key <= {w0_next, w1_next, w2_next, w3_next};
        end
    end

endmodule