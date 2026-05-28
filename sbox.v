module sbox(a,c);

input  [7:0] a; 
output reg [7:0] c;
    
    
    
   always @(a)
    case (a)
      8'h00: c=8'h63;
	   8'h01: c=8'h7c;
	   8'h02: c=8'h77;
	   8'h03: c=8'h7b;
	   8'h04: c=8'hf2;
	   8'h05: c=8'h6b;
	   8'h06: c=8'h6f;
	   8'h07: c=8'hc5;
	   8'h08: c=8'h30;
	   8'h09: c=8'h01;
	   8'h0a: c=8'h67;
	   8'h0b: c=8'h2b;
	   8'h0c: c=8'hfe;
	   8'h0d: c=8'hd7;
	   8'h0e: c=8'hab;
	   8'h0f: c=8'h76;
	   8'h10: c=8'hca;
	   8'h11: c=8'h82;
	   8'h12: c=8'hc9;
	   8'h13: c=8'h7d;
	   8'h14: c=8'hfa;
	   8'h15: c=8'h59;
	   8'h16: c=8'h47;
	   8'h17: c=8'hf0;
	   8'h18: c=8'had;
	   8'h19: c=8'hd4;
	   8'h1a: c=8'ha2;
	   8'h1b: c=8'haf;
	   8'h1c: c=8'h9c;
	   8'h1d: c=8'ha4;
	   8'h1e: c=8'h72;
	   8'h1f: c=8'hc0;
	   8'h20: c=8'hb7;
	   8'h21: c=8'hfd;
	   8'h22: c=8'h93;
	   8'h23: c=8'h26;
	   8'h24: c=8'h36;
	   8'h25: c=8'h3f;
	   8'h26: c=8'hf7;
	   8'h27: c=8'hcc;
	   8'h28: c=8'h34;
	   8'h29: c=8'ha5;
	   8'h2a: c=8'he5;
	   8'h2b: c=8'hf1;
	   8'h2c: c=8'h71;
	   8'h2d: c=8'hd8;
	   8'h2e: c=8'h31;
	   8'h2f: c=8'h15;
	   8'h30: c=8'h04;
	   8'h31: c=8'hc7;
	   8'h32: c=8'h23;
	   8'h33: c=8'hc3;
	   8'h34: c=8'h18;
	   8'h35: c=8'h96;
	   8'h36: c=8'h05;
	   8'h37: c=8'h9a;
	   8'h38: c=8'h07;
	   8'h39: c=8'h12;
	   8'h3a: c=8'h80;
	   8'h3b: c=8'he2;
	   8'h3c: c=8'heb;
	   8'h3d: c=8'h27;
	   8'h3e: c=8'hb2;
	   8'h3f: c=8'h75;
	   8'h40: c=8'h09;
	   8'h41: c=8'h83;
	   8'h42: c=8'h2c;
	   8'h43: c=8'h1a;
	   8'h44: c=8'h1b;
	   8'h45: c=8'h6e;
	   8'h46: c=8'h5a;
	   8'h47: c=8'ha0;
	   8'h48: c=8'h52;
	   8'h49: c=8'h3b;
	   8'h4a: c=8'hd6;
	   8'h4b: c=8'hb3;
	   8'h4c: c=8'h29;
	   8'h4d: c=8'he3;
	   8'h4e: c=8'h2f;
	   8'h4f: c=8'h84;
	   8'h50: c=8'h53;
	   8'h51: c=8'hd1;
	   8'h52: c=8'h00;
	   8'h53: c=8'hed;
	   8'h54: c=8'h20;
	   8'h55: c=8'hfc;
	   8'h56: c=8'hb1;
	   8'h57: c=8'h5b;
	   8'h58: c=8'h6a;
	   8'h59: c=8'hcb;
	   8'h5a: c=8'hbe;
	   8'h5b: c=8'h39;
	   8'h5c: c=8'h4a;
	   8'h5d: c=8'h4c;
	   8'h5e: c=8'h58;
	   8'h5f: c=8'hcf;
	   8'h60: c=8'hd0;
	   8'h61: c=8'hef;
	   8'h62: c=8'haa;
	   8'h63: c=8'hfb;
	   8'h64: c=8'h43;
	   8'h65: c=8'h4d;
	   8'h66: c=8'h33;
	   8'h67: c=8'h85;
	   8'h68: c=8'h45;
	   8'h69: c=8'hf9;
	   8'h6a: c=8'h02;
	   8'h6b: c=8'h7f;
	   8'h6c: c=8'h50;
	   8'h6d: c=8'h3c;
	   8'h6e: c=8'h9f;
	   8'h6f: c=8'ha8;
	   8'h70: c=8'h51;
	   8'h71: c=8'ha3;
	   8'h72: c=8'h40;
	   8'h73: c=8'h8f;
	   8'h74: c=8'h92;
	   8'h75: c=8'h9d;
	   8'h76: c=8'h38;
	   8'h77: c=8'hf5;
	   8'h78: c=8'hbc;
	   8'h79: c=8'hb6;
	   8'h7a: c=8'hda;
	   8'h7b: c=8'h21;
	   8'h7c: c=8'h10;
	   8'h7d: c=8'hff;
	   8'h7e: c=8'hf3;
	   8'h7f: c=8'hd2;
	   8'h80: c=8'hcd;
	   8'h81: c=8'h0c;
	   8'h82: c=8'h13;
	   8'h83: c=8'hec;
	   8'h84: c=8'h5f;
	   8'h85: c=8'h97;
	   8'h86: c=8'h44;
	   8'h87: c=8'h17;
	   8'h88: c=8'hc4;
	   8'h89: c=8'ha7;
	   8'h8a: c=8'h7e;
	   8'h8b: c=8'h3d;
	   8'h8c: c=8'h64;
	   8'h8d: c=8'h5d;
	   8'h8e: c=8'h19;
	   8'h8f: c=8'h73;
	   8'h90: c=8'h60;
	   8'h91: c=8'h81;
	   8'h92: c=8'h4f;
	   8'h93: c=8'hdc;
	   8'h94: c=8'h22;
	   8'h95: c=8'h2a;
	   8'h96: c=8'h90;
	   8'h97: c=8'h88;
	   8'h98: c=8'h46;
	   8'h99: c=8'hee;
	   8'h9a: c=8'hb8;
	   8'h9b: c=8'h14;
	   8'h9c: c=8'hde;
	   8'h9d: c=8'h5e;
	   8'h9e: c=8'h0b;
	   8'h9f: c=8'hdb;
	   8'ha0: c=8'he0;
	   8'ha1: c=8'h32;
	   8'ha2: c=8'h3a;
	   8'ha3: c=8'h0a;
	   8'ha4: c=8'h49;
	   8'ha5: c=8'h06;
	   8'ha6: c=8'h24;
	   8'ha7: c=8'h5c;
	   8'ha8: c=8'hc2;
	   8'ha9: c=8'hd3;
	   8'haa: c=8'hac;
	   8'hab: c=8'h62;
	   8'hac: c=8'h91;
	   8'had: c=8'h95;
	   8'hae: c=8'he4;
	   8'haf: c=8'h79;
	   8'hb0: c=8'he7;
	   8'hb1: c=8'hc8;
	   8'hb2: c=8'h37;
	   8'hb3: c=8'h6d;
	   8'hb4: c=8'h8d;
	   8'hb5: c=8'hd5;
	   8'hb6: c=8'h4e;
	   8'hb7: c=8'ha9;
	   8'hb8: c=8'h6c;
	   8'hb9: c=8'h56;
	   8'hba: c=8'hf4;
	   8'hbb: c=8'hea;
	   8'hbc: c=8'h65;
	   8'hbd: c=8'h7a;
	   8'hbe: c=8'hae;
	   8'hbf: c=8'h08;
	   8'hc0: c=8'hba;
	   8'hc1: c=8'h78;
	   8'hc2: c=8'h25;
	   8'hc3: c=8'h2e;
	   8'hc4: c=8'h1c;
	   8'hc5: c=8'ha6;
	   8'hc6: c=8'hb4;
	   8'hc7: c=8'hc6;
	   8'hc8: c=8'he8;
	   8'hc9: c=8'hdd;
	   8'hca: c=8'h74;
	   8'hcb: c=8'h1f;
	   8'hcc: c=8'h4b;
	   8'hcd: c=8'hbd;
	   8'hce: c=8'h8b;
	   8'hcf: c=8'h8a;
	   8'hd0: c=8'h70;
	   8'hd1: c=8'h3e;
	   8'hd2: c=8'hb5;
	   8'hd3: c=8'h66;
	   8'hd4: c=8'h48;
	   8'hd5: c=8'h03;
	   8'hd6: c=8'hf6;
	   8'hd7: c=8'h0e;
	   8'hd8: c=8'h61;
	   8'hd9: c=8'h35;
	   8'hda: c=8'h57;
	   8'hdb: c=8'hb9;
	   8'hdc: c=8'h86;
	   8'hdd: c=8'hc1;
	   8'hde: c=8'h1d;
	   8'hdf: c=8'h9e;
	   8'he0: c=8'he1;
	   8'he1: c=8'hf8;
	   8'he2: c=8'h98;
	   8'he3: c=8'h11;
	   8'he4: c=8'h69;
	   8'he5: c=8'hd9;
	   8'he6: c=8'h8e;
	   8'he7: c=8'h94;
	   8'he8: c=8'h9b;
	   8'he9: c=8'h1e;
	   8'hea: c=8'h87;
	   8'heb: c=8'he9;
	   8'hec: c=8'hce;
	   8'hed: c=8'h55;
	   8'hee: c=8'h28;
	   8'hef: c=8'hdf;
	   8'hf0: c=8'h8c;
	   8'hf1: c=8'ha1;
	   8'hf2: c=8'h89;
	   8'hf3: c=8'h0d;
	   8'hf4: c=8'hbf;
	   8'hf5: c=8'he6;
	   8'hf6: c=8'h42;
	   8'hf7: c=8'h68;
	   8'hf8: c=8'h41;
	   8'hf9: c=8'h99;
	   8'hfa: c=8'h2d;
	   8'hfb: c=8'h0f;
	   8'hfc: c=8'hb0;
	   8'hfd: c=8'h54;
	   8'hfe: c=8'hbb;
	   8'hff: c=8'h16;
	endcase

endmodule


// =============================================================
//  AES S-Box using Composite Field Arithmetic
//  Based on: Canright, "A Very Compact S-Box for AES" (2005)
//  Field tower: GF(2^8) -> GF((2^4)^2) -> GF(((2^2)^2)^2)
//
//  Compared to LUT-based S-Box:
//  Area    : ~4x smaller (~92-150 GE vs ~800 GE)
//  Timing  : Slightly longer critical path
//  Power   : Lower static, higher dynamic
// =============================================================
// module sbox(input [7:0]a, output [7:0]c);
//   wire [7:0]	temp1;
//   wire [7:0]	temp2;
//   wire [7:0]	temp3;
  
//   composite_transformation composite_transformation(.in(a),.out(temp1));
  
//   inverse_in_comp_gf_2_4 inverse_in_comp_gf_2_4(.a(temp1),.c(temp2));
  
//   inverse_composite_transformation inverse_composite_transformation(.in(temp2),.out(temp3));
  
//   Affine_map Affine_map(.in(temp3),.out(c));
  
// endmodule

// module composite_transformation(input [7:0]in,output [7:0]out);
//   assign out[7] =in[7] ^ in[5];
//   assign out[6] =in[7] ^ in[5] ^ in[3] ^ in[2];
//   assign out[5] =in[7] ^ in[6] ^ in[4] ^ in[1];
//   assign out[4] =in[6] ^ in[5] ^ in[4] ;
//   assign out[3] =in[7] ^ in[6] ^ in[2] ^ in[1];
//   assign out[2] =in[6] ^ in[4] ^ in[1] ;
//   assign out[1] =in[3] ^ in[1] ;
//   assign out[0] =in[7] ^ in[6] ^ in[4] ^ in[3] ^ in[2] ^ in[0];
  
// endmodule

// module inverse_composite_transformation(input [7:0]in,output [7:0]out);
//   assign out[0]=  in[6] ^ in[4] ^ in[0];
//   assign out[1]=  in[7] ^ in[5] ^ in[4];
//   assign out[2]=  in[6] ^ in[5] ^ in[4] ^ in[1];
//   assign out[3]=  in[7] ^ in[5] ^ in[4] ^ in[1] ;
//   assign out[4]=  in[6] ^ in[4] ^ in[3] ^ in[1];
//   assign out[5]=  in[7] ^ in[5] ^ in[2];
//   assign out[6]=  in[7] ^ in[6] ^ in[5] ^ in[3] ^ in[2] ^ in[1];
//   assign out[7]=  in[5] ^ in[2];
// endmodule

// module inverse_in_comp_gf_2_4(input [7:0]a,output [7:0]c);
//   wire [3:0]ah;
//   wire [3:0]al;
//   wire [3:0]t;
//   assign t =4'b1;
//   wire [3:0]u;
//   assign u = 4'h9;
//   wire [3:0]A_sq;
//   wire [3:0]sq_mul_u;
//   wire [3:0]B_sq;
//   wire [3:0]AB;
//   wire [3:0]inv;
//   assign al[0]=a[0];
//   assign al[1]=a[1];
//   assign al[2]=a[2];
//   assign al[3]=a[3];
//   assign ah[0]=a[4];
//   assign ah[1]=a[5];
//   assign ah[2]=a[6];
//   assign ah[3]=a[7];
//   wire [3:0]d0;
//   wire [3:0]d1;
  
//   comp_sqr 		sqr1( .x(ah), .out(A_sq));
//   comp_mult 	mult1( .x(u), .y(A_sq), .out(sq_mul_u));  
//   comp_sqr 		sqr2( .x(al), .out(B_sq));
//   comp_mult 	mult2( .x(ah), .y(al), .out(AB));
//   comp_inverse 	commoninv( .in((sq_mul_u^B_sq^AB) ), .out(inv) );
//   comp_mult	 	mult3( .x(ah), .y(inv), .out(d1));  
//   comp_mult 	mult4( .x(ah^al), .y(inv), .out(d0));
  
//   assign c[0]=d0[0];
//   assign c[1]=d0[1];
//   assign c[2]=d0[2];
//   assign c[3]=d0[3];
//   assign c[4]=d1[0];
//   assign c[5]=d1[1];
//   assign c[6]=d1[2];
//   assign c[7]=d1[3];
  
// endmodule

// module comp_sqr(input [3:0]x , output [3:0]out);
//   assign out[3]=x[3];
//   assign out[2]=x[3]^x[1];
//   assign out[1]=x[2];
//   assign out[0]=x[2]^x[0];
// endmodule

// module comp_mult( input [3:0]x,input [3:0]y, output [3:0]out);
//   wire [6:0]c;
//   assign c[0]=(x[0]&y[0]);
//   assign c[1]=(x[0]&y[1] ^ x[1]&y[0]);
//   assign c[2]=(x[0]&y[2] ^ x[1]&y[1] ^ x[2]&y[0]);
//   assign c[3]=(x[0]&y[3] ^ x[1]&y[2] ^ x[2]&y[1]  ^ x[3]&y[0]);
//   assign c[4]=(x[3]&y[1] ^ x[2]&y[2] ^ x[1]&y[3]);
//   assign c[5]=(x[3]&y[2] ^ x[2]&y[3]);
//   assign c[6]=(x[3]&y[3]);
//   assign out[3]= ( c[6] ^ c[3]) ;
//   assign out[2]= ( c[6] ^ c[5] ^ c[2] );
//   assign out[1]= ( c[5] ^ c[4] ^ c[1] );
//   assign out[0]= ( c[4] ^ c[0] );
// endmodule

// module comp_inverse(input [3:0]in ,output [3:0]out);
//   reg [3:0] outputbyte;
//   always @ (in)
//     begin
//       case(in)
//       	4'h0 : outputbyte = 4'h0;
//       	4'h1 : outputbyte = 4'h1;
//       	4'h2 : outputbyte = 4'h9;
//       	4'h3 : outputbyte = 4'he;
//       	4'h4 : outputbyte = 4'hd;
//       	4'h5 : outputbyte = 4'hb;
//       	4'h6 : outputbyte = 4'h7;
//       	4'h7 : outputbyte = 4'h6;
//       	4'h8 : outputbyte = 4'hf;
//       	4'h9 : outputbyte = 4'h2;
//       	4'ha : outputbyte = 4'hc;
//       	4'hb : outputbyte = 4'h5;
//       	4'hc : outputbyte = 4'ha;
//       	4'hd : outputbyte = 4'h4;
//       	4'he : outputbyte = 4'h3;
//       	4'hf : outputbyte = 4'h8;
//       endcase
//     end
//   assign out[0]=outputbyte[0];
//   assign out[1]=outputbyte[1];
//   assign out[2]=outputbyte[2];
//   assign out[3]=outputbyte[3];
  
// endmodule


// module Affine_map(input [7:0]in ,output [7:0]out);
//   assign out[0]= 1 ^ in[0] ^ in[4] ^ in[5] ^ in[6] ^ in[7];
//   assign out[1]= 1 ^ in[0] ^ in[1] ^ in[5] ^ in[6] ^ in[7];
//   assign out[2]= 0 ^ in[0] ^ in[1] ^ in[2] ^ in[6] ^ in[7];
//   assign out[3]= 0 ^ in[0] ^ in[1] ^ in[2] ^ in[3] ^ in[7];
//   assign out[4]= 0 ^ in[0] ^ in[1] ^ in[2] ^ in[3] ^ in[4];
//   assign out[5]= 1 ^ in[1] ^ in[2] ^ in[3] ^ in[4] ^ in[5];
//   assign out[6]= 1 ^ in[2] ^ in[3] ^ in[4] ^ in[5] ^ in[6];
//   assign out[7]= 0 ^ in[3] ^ in[4] ^ in[5] ^ in[6] ^ in[7];
// endmodule