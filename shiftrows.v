// module shiftrows (
//     input  [127:0] state_in,
//     output [127:0] state_out
// );

//     // Row 0: Bytes {0, 4, 8, 12} -> No Shift
//     assign state_out[7:0]          = state_in[7:0];     // Byte 0
//     assign state_out[39:32]        = state_in[39:32];   // Byte 4
//     assign state_out[71:64]        = state_in[71:64];   // Byte 8
//     assign state_out[103:96]       = state_in[103:96];  // Byte 12

//     // Row 1: Bytes {1, 5, 9, 13} -> Shift Left 1
//     // (1<-5, 5<-9, 9<-13, 13<-1)
//     assign state_out[15:8]         = state_in[47:40];   // Byte 5 -> 1
//     assign state_out[47:40]        = state_in[79:72];   // Byte 9 -> 5
//     assign state_out[79:72]        = state_in[111:104]; // Byte 13 -> 9
//     assign state_out[111:104]      = state_in[15:8];    // Byte 1 -> 13

//     // Row 2: Bytes {2, 6, 10, 14} -> Shift Left 2
//     // (2<-10, 6<-14, 10<-2, 14<-6)
//     assign state_out[23:16]        = state_in[87:80];   // Byte 10 -> 2
//     assign state_out[55:48]        = state_in[119:112]; // Byte 14 -> 6
//     assign state_out[87:80]        = state_in[23:16];   // Byte 2 -> 10
//     assign state_out[119:112]      = state_in[55:48];   // Byte 6 -> 14

//     // Row 3: Bytes {3, 7, 11, 15} -> Shift Left 3
//     // (3<-15, 7<-3, 11<-7, 15<-11)
//     assign state_out[31:24]        = state_in[127:120]; // Byte 15 -> 3
//     assign state_out[63:56]        = state_in[31:24];   // Byte 3 -> 7
//     assign state_out[95:88]        = state_in[63:56];   // Byte 7 -> 11
//     assign state_out[127:120]      = state_in[95:88];   // Byte 11 -> 15

// endmodule

module shiftrows (
    input  wire [127:0] state_in,
    output wire [127:0] state_out
);

    // Row 0: Bytes 0, 4, 8, 12 (No Shift)
    assign state_out[127:120] = state_in[127:120]; // 0 -> 0
    assign state_out[95:88]   = state_in[95:88];   // 4 -> 4
    assign state_out[63:56]   = state_in[63:56];   // 8 -> 8
    assign state_out[31:24]   = state_in[31:24];   // 12 -> 12

    // Row 1: Bytes 1, 5, 9, 13 (Left Shift 1)
    // 5 goes to 1, 9 goes to 5, 13 goes to 9, 1 goes to 13
    assign state_out[119:112] = state_in[87:80];   // 1  <- 5
    assign state_out[87:80]   = state_in[55:48];   // 5  <- 9
    assign state_out[55:48]   = state_in[23:16];   // 9  <- 13
    assign state_out[23:16]   = state_in[119:112]; // 13 <- 1

    // Row 2: Bytes 2, 6, 10, 14 (Left Shift 2)
    // 10 goes to 2, 14 goes to 6, 2 goes to 10, 6 goes to 14
    assign state_out[111:104] = state_in[47:40];   // 2  <- 10
    assign state_out[79:72]   = state_in[15:8];   // 6  <- 14
    assign state_out[47:40]   = state_in[111:104]; // 10 <- 2
    assign state_out[15:8]    = state_in[79:72];   // 14 <- 6

    // Row 3: Bytes 3, 7, 11, 15 (Left Shift 3)
    // 15 goes to 3, 3 goes to 7, 7 goes to 11, 11 goes to 15
    assign state_out[103:96]  = state_in[7:0];   // 3  <- 15
    assign state_out[71:64]   = state_in[103:96];  // 7  <- 3
    assign state_out[39:32]   = state_in[71:64];   // 11 <- 7
    assign state_out[7:0]     = state_in[39:32];   // 15 <- 11

endmodule

// module shiftrows (
//     input  wire [127:0] state_in,
//     output wire [127:0] state_out
// );

//     wire [7:0] b [0:15];
//     wire [7:0] s [0:15];

//     genvar i;

//     // ----------------------------
//     // Unpack (MSB FIRST — critical)
//     // ----------------------------
//     generate
//         for (i = 0; i < 16; i = i + 1) begin : UNPACK
//             assign b[i] = state_in[127 - i*8 -: 8];
//         end
//     endgenerate

//     // ----------------------------
//     // ShiftRows (CORRECT AES mapping)
//     // ----------------------------

//     // Row 0 (no shift)
//     assign s[0]  = b[0];
//     assign s[4]  = b[4];
//     assign s[8]  = b[8];
//     assign s[12] = b[12];

//     // Row 1 (shift left by 1)
//     assign s[1]  = b[5];
//     assign s[5]  = b[9];
//     assign s[9]  = b[13];
//     assign s[13] = b[1];

//     // Row 2 (shift left by 2)
//     assign s[2]  = b[10];
//     assign s[6]  = b[14];
//     assign s[10] = b[2];
//     assign s[14] = b[6];

//     // Row 3 (shift left by 3)
//     assign s[3]  = b[15];
//     assign s[7]  = b[3];
//     assign s[11] = b[7];
//     assign s[15] = b[11];

//     // ----------------------------
//     // Pack
//     // ----------------------------
//     generate
//         for (i = 0; i < 16; i = i + 1) begin : PACK
//             assign state_out[127 - i*8 -: 8] = s[i];
//         end
//     endgenerate

// endmodule

// module shiftrows (
//     input  wire [127:0] state_in,
//     output wire [127:0] state_out
// );

//     wire [7:0] b [0:15];

//     // Unpack (MSB-first)
//     genvar i;
//     generate
//         for (i = 0; i < 16; i = i + 1) begin
//             assign b[i] = state_in[127 - i*8 -: 8];
//         end
//     endgenerate

//     // Direct mapping (NO intermediate s[] confusion)

//     assign state_out = {
//         // Column 0
//         b[0],   // row0
//         b[5],   // row1 shift
//         b[10],  // row2 shift
//         b[15],  // row3 shift

//         // Column 1
//         b[4],
//         b[9],
//         b[14],
//         b[3],

//         // Column 2
//         b[8],
//         b[13],
//         b[2],
//         b[7],

//         // Column 3
//         b[12],
//         b[1],
//         b[6],
//         b[11]
//     };

// endmodule