// module aes_cipher_top (
//     input  wire         clk,
//     input  wire         rst_n,
//     input  wire         start,
//     input  wire [127:0] plaintext,
//     input  wire [127:0] key,
//     output reg  [127:0] ciphertext,
//     output reg          done
// );

//     // ---------------------------------------------------------
//     // FSM State Encoding — all 4-bit
//     // ---------------------------------------------------------
//     localparam [3:0]
//         ST_IDLE       = 4'd0,
//         ST_LOAD_WAIT  = 4'd1,
//         ST_INIT_ARK   = 4'd2,
//         ST_KEY_UPDATE = 4'd3,
//         ST_KEY_WAIT   = 4'd4,
//         ST_SUBBYTES   = 4'd5,
//         ST_SB_LATCH   = 4'd6,
//         ST_SHIFTROWS  = 4'd7,
//         ST_DONE       = 4'd8;

//     reg [3:0] state, next_state;

//     reg [3:0]   round;
//     reg [127:0] state_reg;

//     // ---------------------------------------------------------
//     // SubBytes
//     // ---------------------------------------------------------
//     reg          sb_start;
//     wire [127:0] sb_state_out;
//     wire         sb_done;

//     subbytes u_subbytes (
//         .clk       (clk),
//         .reset     (~rst_n),
//         .start     (sb_start),
//         .state_in  (state_reg),
//         .state_out (sb_state_out),
//         .done      (sb_done)
//     );

//     // ---------------------------------------------------------
//     // ShiftRows (combinational)
//     // ---------------------------------------------------------
//     wire [127:0] sr_state_out;

//     shiftrows u_shiftrows (
//         .state_in  (state_reg),
//         .state_out (sr_state_out)
//     );

//     // ---------------------------------------------------------
//     // KeyExpansion
//     // ---------------------------------------------------------
//     reg          ke_load_key;
//     reg          ke_update_key;
//     wire [127:0] round_key;

//     keyexpansion u_keyexpansion (
//         .clk        (clk),
//         .rst_n      (rst_n),
//         .load_key   (ke_load_key),
//         .update_key (ke_update_key),
//         .key_in     (key),
//         .round_in   (round),
//         .round_key  (round_key)
//     );

//     // ---------------------------------------------------------
//     // AddRoundKey (combinational)
//     // ---------------------------------------------------------
//     wire [127:0] ark_state_out;

//     addroundkey u_addroundkey (
//         .state_in  (state_reg),
//         .round_key (round_key),
//         .state_out (ark_state_out)
//     );

//     // ---------------------------------------------------------
//     // FSM sequential
//     // ---------------------------------------------------------
//     always @(posedge clk or negedge rst_n) begin
//         if (!rst_n) state <= ST_IDLE;
//         else        state <= next_state;
//     end

//     // ---------------------------------------------------------
//     // FSM combinational
//     // ---------------------------------------------------------
//     always @(*) begin
//         next_state = state;
//         case (state)
//             ST_IDLE:       next_state = start ? ST_LOAD_WAIT : ST_IDLE;
//             ST_LOAD_WAIT:  next_state = ST_INIT_ARK;
//             ST_INIT_ARK:   next_state = ST_KEY_UPDATE;
//             ST_KEY_UPDATE: next_state = ST_KEY_WAIT;
//             ST_KEY_WAIT:   next_state = ST_SUBBYTES;
//             ST_SUBBYTES:   next_state = sb_done ? ST_SB_LATCH : ST_SUBBYTES;
//             ST_SB_LATCH:   next_state = ST_SHIFTROWS;
//             ST_SHIFTROWS:  next_state = ST_DONE;
//             ST_DONE:       next_state = ST_IDLE;
//             default:       next_state = ST_IDLE;
//         endcase
//     end

//     // ---------------------------------------------------------
//     // FSM datapath
//     // ---------------------------------------------------------
//     always @(posedge clk or negedge rst_n) begin
//         if (!rst_n) begin
//             state_reg     <= 128'd0;
//             round         <= 4'd0;
//             sb_start      <= 1'b0;
//             ke_load_key   <= 1'b0;
//             ke_update_key <= 1'b0;
//             ciphertext    <= 128'd0;
//             done          <= 1'b0;
//         end else begin
//             sb_start      <= 1'b0;
//             ke_load_key   <= 1'b0;
//             ke_update_key <= 1'b0;
//             done          <= 1'b0;

//             case (state)
//                 ST_IDLE: begin
//                     if (start) begin
//                         state_reg   <= plaintext;
//                         round       <= 4'd0;
//                         ke_load_key <= 1'b1;
//                     end
//                 end

//                 ST_INIT_ARK: begin
//                     state_reg <= ark_state_out;
//                     round     <= 4'd1;
//                 end

//                 ST_KEY_UPDATE: begin
//                     ke_update_key <= 1'b1;
//                 end

//                 ST_KEY_WAIT: begin
//                     sb_start <= 1'b1;
//                 end

//                 ST_SB_LATCH: begin
//                     state_reg <= sb_state_out;
//                 end

//                 ST_SHIFTROWS: begin
//                     state_reg <= sr_state_out;
//                 end

//                 ST_DONE: begin
//                     ciphertext <= state_reg;
//                     done       <= 1'b1;
//                 end

//                 default: ;
//             endcase
//         end
//     end

// endmodule
// module aes_cipher_top (
//     input  wire         clk,
//     input  wire         rst_n,
//     input  wire         start,
//     input  wire [127:0] plaintext,
//     input  wire [127:0] key,
//     output reg  [127:0] ciphertext,
//     output reg          done
// );

//     localparam IDLE        = 4'd0,
//                KEY_WAIT    = 4'd1,
//                INIT        = 4'd2,
//                SUB_START   = 4'd3,
//                SUB_WAIT    = 4'd4,
//                SHIFT       = 4'd5,
//                MIX_START   = 4'd6,
//                MIX_WAIT    = 4'd7,
//                HOLD        = 4'd8; 

//     reg [3:0] state;
//     reg [127:0] state_reg;
//     reg [1:0]   col_idx; // Tracks column 0, 1, 2, or 3

//     // SubBytes & ShiftRows Signals
//     reg sub_start;
//     wire sub_done;
//     wire [127:0] sub_out, shift_out;

//     // MixColumns Signals
//     reg mix_start;
//     wire mix_done;
//     reg [31:0] mix_in;
//     wire [31:0] mix_out;

//     // Key Expansion
//     wire [127:0] round_key;

//     // Modules
//     keyexpansion key_unit (.clk(clk), .rst_n(rst_n), .load_key(start), .update_key(1'b0), .key_in(key), .round_in(4'd0), .round_key(round_key));
//     subbytes     sub_unit (.clk(clk), .reset(!rst_n), .start(sub_start), .state_in(state_reg), .state_out(sub_out), .done(sub_done));
//     shiftrows    shift_unit (.state_in(sub_out), .state_out(shift_out));
    
//     mixcolumns   mix_unit (
//         .clk(clk), .rst_n(rst_n), 
//         .start(mix_start), 
//         .col_in(mix_in), 
//         .col_out(mix_out), 
//         .done(mix_done)
//     );

//     // MixColumns Input Mux (Column Selection)
//     always @(*) begin
//         case(col_idx)
//             2'd0: mix_in = state_reg[127:96];
//             2'd1: mix_in = state_reg[95:64];
//             2'd2: mix_in = state_reg[63:32];
//             2'd3: mix_in = state_reg[31:0];
//             default: mix_in = 32'd0;
//         endcase
//     end

//     // FSM Logic
//     always @(posedge clk or negedge rst_n) begin
//         if (!rst_n) begin
//             state <= IDLE; state_reg <= 0; done <= 0;
//             sub_start <= 0; mix_start <= 0; col_idx <= 0;
//         end else begin
//             sub_start <= 0; mix_start <= 0; // Pulse defaults

//             case(state)
//                 IDLE: begin
//                     done <= 0;
//                     if (start) state <= KEY_WAIT;
//                 end
                
//                 KEY_WAIT: state <= INIT;

//                 INIT: begin
//                     state_reg <= plaintext ^ round_key;
//                     state <= SUB_START;
//                 end

//                 SUB_START: begin
//                     sub_start <= 1;
//                     state <= SUB_WAIT;
//                 end

//                 SUB_WAIT: begin
//                     if (sub_done) begin
//                         state_reg <= shift_out; // ShiftRows is combinational
//                         state <= MIX_START;
//                         col_idx <= 0;
//                     end
//                 end

//                 MIX_START: begin
//                     mix_start <= 1;
//                     state <= MIX_WAIT;
//                 end

//                 MIX_WAIT: begin
//                     if (mix_done) begin
//                         // Store the mixed column back into the state_reg
//                         case(col_idx)
//                             2'd0: state_reg[127:96] <= mix_out;
//                             2'd1: state_reg[95:64]  <= mix_out;
//                             2'd2: state_reg[63:32]  <= mix_out;
//                             2'd3: state_reg[31:0]   <= mix_out;
//                         endcase
                        
//                         if (col_idx == 2'd3) state <= HOLD;
//                         else begin
//                             col_idx <= col_idx + 1;
//                             state <= MIX_START; // Process next column
//                         end
//                     end
//                 end

//                 HOLD: begin
//                     ciphertext <= state_reg;
//                     done <= 1;
//                     if (!start) state <= IDLE;
//                 end

//                 default: state <= IDLE;
//             endcase
//         end
//     end
// endmodule


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

module aes_cipher_top (
    input  wire         clk,
    input  wire         rst_n,
    input  wire         start,
    input  wire [127:0] plaintext,
    input  wire [127:0] key,
    output reg  [127:0] ciphertext,
    output reg          done
);

    // ---------------------------------------------------------
    // FSM State Encoding
    // ---------------------------------------------------------
    localparam [3:0]
        IDLE        = 4'd0,
        LOAD_WAIT   = 4'd1,   // wait for round_key to load key_in
        INIT_ARK    = 4'd2,   // state = plaintext XOR key (round 0)
        KEY_UPD     = 4'd3,   // pulse update_key for next round
        KEY_WAIT    = 4'd4,   // wait one cycle for round_key to settle
        SUB_ST      = 4'd5,   // pulse sub_start
        SUB_WAIT    = 4'd6,   // wait for sub_done
        SB_LATCH    = 4'd7,   // latch sb_out (one extra cycle for state_out settle)
        SHIFT       = 4'd8,   // latch shift_out (combinational, one cycle)
        MIX_ST      = 4'd9,   // pulse mix_start
        MIX_WAIT    = 4'd10,  // wait for mix_done
        ADD_KEY     = 4'd11,  // state_reg XOR round_key
        DONE_ST     = 4'd12;

    reg [3:0] state, next_state;
    reg [3:0] round;
    reg [127:0] state_reg;

    // ---------------------------------------------------------
    // Control signals
    // ---------------------------------------------------------
    reg sub_start, mix_start, load_key, key_update;

    // ---------------------------------------------------------
    // SubBytes
    // ---------------------------------------------------------
    wire [127:0] sub_out;
    wire         sub_done;

    subbytes sub_unit (
        .clk      (clk),
        .reset    (~rst_n),
        .start    (sub_start),
        .state_in (state_reg),
        .state_out(sub_out),
        .done     (sub_done)
    );

    // ---------------------------------------------------------
    // ShiftRows (combinational)
    // ---------------------------------------------------------
    wire [127:0] shift_out;

    shiftrows shift_unit (
        .state_in (state_reg),
        .state_out(shift_out)
    );

    // ---------------------------------------------------------
    // MixColumns
    // ---------------------------------------------------------
    wire [127:0] mix_out;
    wire         mix_done;

    mixcolumns mix_unit (
        .clk      (clk),
        .rst_n    (rst_n),
        .start    (mix_start),
        .state_in (state_reg),
        .state_out(mix_out),
        .done     (mix_done)
    );

    // ---------------------------------------------------------
    // KeyExpansion
    // ---------------------------------------------------------
    wire [127:0] round_key;

    keyexpansion key_unit (
        .clk       (clk),
        .rst_n     (rst_n),
        .load_key  (load_key),
        .update_key(key_update),
        .key_in    (key),
        .round_in  (round),
        .round_key (round_key)
    );

    // ---------------------------------------------------------
    // FSM — sequential
    // ---------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) state <= IDLE;
        else        state <= next_state;
    end

    // ---------------------------------------------------------
    // FSM — combinational next-state
    // ---------------------------------------------------------
    always @(*) begin
        next_state = state;
        case (state)
            IDLE:     next_state = start    ? LOAD_WAIT : IDLE;
            LOAD_WAIT:next_state = INIT_ARK;
            INIT_ARK: next_state = KEY_UPD;
            KEY_UPD:  next_state = KEY_WAIT;
            KEY_WAIT: next_state = SUB_ST;
            SUB_ST:   next_state = SUB_WAIT;
            SUB_WAIT: next_state = sub_done ? SB_LATCH : SUB_WAIT;
            SB_LATCH: next_state = SHIFT;
            SHIFT:    next_state = (round == 4'd10) ? ADD_KEY : MIX_ST;
            MIX_ST:   next_state = MIX_WAIT;
            MIX_WAIT: next_state = mix_done ? ADD_KEY : MIX_WAIT;
            ADD_KEY:  next_state = (round == 4'd10) ? DONE_ST : KEY_UPD;
            DONE_ST:  next_state = IDLE;
            default:  next_state = IDLE;
        endcase
    end

    // ---------------------------------------------------------
    // FSM — datapath
    // ---------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_reg  <= 128'd0;
            round      <= 4'd0;
            sub_start  <= 1'b0;
            mix_start  <= 1'b0;
            load_key   <= 1'b0;
            key_update <= 1'b0;
            ciphertext <= 128'd0;
            done       <= 1'b0;
        end else begin
            // Default: clear all pulses every cycle
            sub_start  <= 1'b0;
            mix_start  <= 1'b0;
            load_key   <= 1'b0;
            key_update <= 1'b0;
            done       <= 1'b0;

            case (state)
                IDLE: begin
                    if (start) begin
                        state_reg <= plaintext;
                        round     <= 4'd0;
                        load_key  <= 1'b1;  // load key_in into round_key
                    end
                end

                // LOAD_WAIT: round_key now holds key_in (settled after load_key pulse)

                INIT_ARK: begin
                    // Round 0 AddRoundKey: plaintext XOR original key
                    state_reg <= state_reg ^ round_key;
                    round     <= 4'd1;      // next update_key will produce round key 1
                end

                KEY_UPD: begin
                    key_update <= 1'b1;     // advance round_key to round_key[round]
                end

                // KEY_WAIT: round_key[round] now settled

                SUB_ST: begin
                    sub_start <= 1'b1;
                end

                SUB_WAIT: begin
                    // wait — nothing to do
                end

                SB_LATCH: begin
                    state_reg <= sub_out;   // latch after sub_done settled
                end

                SHIFT: begin
                    state_reg <= shift_out; // combinational, registered here
                end

                MIX_ST: begin
                    mix_start <= 1'b1;
                end

                MIX_WAIT: begin
                    if (mix_done)
                        state_reg <= mix_out;
                end

                ADD_KEY: begin
                    state_reg <= state_reg ^ round_key;
                    if (round < 4'd10) begin
                        round <= round + 4'd1;
                    end
                end

                DONE_ST: begin
                    ciphertext <= state_reg;
                    done       <= 1'b1;
                end

                default: ;
            endcase
        end
    end

endmodule