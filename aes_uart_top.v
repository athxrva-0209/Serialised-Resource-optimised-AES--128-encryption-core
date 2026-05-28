// module aes_uart_top #(
//     parameter CLKS_PER_BIT = 10416
// )(
//     input  wire clk,
//     input  wire rst_btn,
//     input  wire rx,
//     output wire tx,
//     output reg  led_rx_busy,
//     output reg  led_encrypting,
//     output reg  led_tx_busy,
//     output reg  led_done
// );

//     // ---------------------------------------------------------
//     // Reset synchronizer
//     // ---------------------------------------------------------
//     reg [3:0] rst_sr = 4'hF;
//     always @(posedge clk)
//         rst_sr <= {rst_sr[2:0], rst_btn};
//     wire rst_n = ~rst_sr[3];

//     // ---------------------------------------------------------
//     // UART RX
//     // ---------------------------------------------------------
//     wire [7:0] rx_data;
//     wire       rx_ready;

//     uart_rx #(.CLKS_PER_BIT(CLKS_PER_BIT)) rx_inst (
//         .clk       (clk),
//         .rx        (rx),
//         .data_out  (rx_data),
//         .byte_ready(rx_ready)
//     );

//     // ---------------------------------------------------------
//     // UART TX
//     // ---------------------------------------------------------
//     reg        tx_start;
//     reg  [7:0] tx_data;
//     wire       tx_busy;

//     uart_tx #(.CLKS_PER_BIT(CLKS_PER_BIT)) tx_inst (
//         .clk      (clk),
//         .tx_start (tx_start),
//         .data_in  (tx_data),
//         .tx_serial(tx),
//         .tx_busy  (tx_busy)
//     );

//     // ---------------------------------------------------------
//     // AES Core
//     // ---------------------------------------------------------
//     reg         aes_start;
//     reg  [127:0] plaintext_reg;
//     reg  [127:0] key_reg;
//     wire [127:0] ciphertext;
//     wire         aes_done;

//     aes_cipher_top aes_core (
//         .clk       (clk),
//         .rst_n     (rst_n),
//         .start     (aes_start),
//         .plaintext (plaintext_reg),
//         .key       (key_reg),
//         .ciphertext(ciphertext),
//         .done      (aes_done)
//     );

//     // ---------------------------------------------------------
//     // FSM
//     // ---------------------------------------------------------
//     localparam [3:0]
//         S_IDLE      = 4'd0,
//         S_RECV_PT   = 4'd1,
//         S_RECV_KEY  = 4'd2,
//         S_START_AES = 4'd3,
//         S_WAIT_AES  = 4'd4,
//         S_SEND_CT   = 4'd5,
//         S_WAIT_TX   = 4'd6;

//     reg [3:0]   state;
//     reg [4:0]   byte_count;
//     reg [127:0] ct_shift;

//     always @(posedge clk or negedge rst_n) begin
//         if (!rst_n) begin
//             state          <= S_IDLE;
//             byte_count     <= 5'd0;
//             plaintext_reg  <= 128'd0;
//             key_reg        <= 128'd0;
//             ct_shift       <= 128'd0;
//             aes_start      <= 1'b0;
//             tx_start       <= 1'b0;
//             tx_data        <= 8'd0;
//             led_rx_busy    <= 1'b0;
//             led_encrypting <= 1'b0;
//             led_tx_busy    <= 1'b0;
//             led_done       <= 1'b0;
//         end else begin
//             aes_start <= 1'b0;
//             tx_start  <= 1'b0;

//             case (state)
//                 S_IDLE: begin
//                     led_rx_busy    <= 1'b0;
//                     led_encrypting <= 1'b0;
//                     led_tx_busy    <= 1'b0;
//                     led_done       <= 1'b0;
//                     byte_count     <= 5'd0;
//                     if (rx_ready) begin
//                         plaintext_reg <= {rx_data, 120'd0};
//                         byte_count    <= 5'd1;
//                         led_rx_busy   <= 1'b1;
//                         state         <= S_RECV_PT;
//                     end
//                 end

//                 S_RECV_PT: begin
//                     if (rx_ready) begin
//                         plaintext_reg <= {plaintext_reg[119:0], rx_data};
//                         byte_count    <= byte_count + 5'd1;
//                         if (byte_count == 5'd15) begin
//                             byte_count <= 5'd0;
//                             state      <= S_RECV_KEY;
//                         end
//                     end
//                 end

//                 S_RECV_KEY: begin
//                     if (rx_ready) begin
//                         key_reg    <= {key_reg[119:0], rx_data};
//                         byte_count <= byte_count + 5'd1;
//                         if (byte_count == 5'd15) begin
//                             byte_count <= 5'd0;
//                             state      <= S_START_AES;
//                         end
//                     end
//                 end

//                 S_START_AES: begin
//                     aes_start      <= 1'b1;
//                     led_rx_busy    <= 1'b0;
//                     led_encrypting <= 1'b1;
//                     state          <= S_WAIT_AES;
//                 end

//                 S_WAIT_AES: begin
//                     if (aes_done) begin
//                         ct_shift       <= ciphertext;
//                         led_encrypting <= 1'b0;
//                         led_done       <= 1'b1;
//                         led_tx_busy    <= 1'b1;
//                         byte_count     <= 5'd0;
//                         state          <= S_SEND_CT;
//                     end
//                 end

//                 S_SEND_CT: begin
//                     if (!tx_busy) begin
//                         tx_data    <= ct_shift[127:120];
//                         tx_start   <= 1'b1;
//                         ct_shift   <= {ct_shift[119:0], 8'd0};
//                         byte_count <= byte_count + 5'd1;
//                         state      <= S_WAIT_TX;
//                     end
//                 end

//                 S_WAIT_TX: begin
//                     if (!tx_busy) begin
//                         if (byte_count == 5'd16) begin
//                             led_tx_busy <= 1'b0;
//                             state       <= S_IDLE;
//                         end else begin
//                             state <= S_SEND_CT;
//                         end
//                     end
//                 end

//                 default: state <= S_IDLE;
//             endcase
//         end
//     end

// endmodule

`timescale 1ns / 1ps

module aes_uart_top(
    input wire clk,         // 100 MHz System Clock
    input wire RsRx,        // UART RX
    output wire RsTx,       // UART TX
    input wire btnC,        // Reset
    input wire sw_encrypt,  // Reserved for future mode select

    output wire [15:0] led  // Debug LEDs
);

initial begin
    $dumpfile("wave.vcd");
    $dumpvars(0, aes_uart_top);
end

    // --- 1. Clock Management (100 MHz -> 10 MHz) ---
    // reg [2:0] clk_counter = 0;
    // reg clk_10mhz_raw = 0;
    
    // always @(posedge clk) begin
    //     if (clk_counter == 4) begin 
    //         clk_counter <= 0;
    //         clk_10mhz_raw <= ~clk_10mhz_raw;
    //     end else begin
    //         clk_counter <= clk_counter + 1;
    //     end
    // end

    // wire sys_clk;
    // BUFG clk_buf (.I(clk_10mhz_raw), .O(sys_clk));

    wire sys_clk = clk;

    // --- 2. Signals ---
    wire [7:0] rx_byte;
    wire rx_ready;
    
    reg tx_start = 0;
    reg [7:0] tx_data = 0;
    wire tx_busy;
    wire tx_serial_wire;
    
    reg [127:0] key_reg = 0;
    reg [127:0] text_reg = 0;
    reg aes_start = 0;
    wire aes_done;
    wire [127:0] aes_result;
    
    reg [4:0] byte_counter = 0;
    reg [1:0] tx_substate = 0;
    
    parameter WAIT_KEY    = 3'b000;
    parameter WAIT_TEXT   = 3'b001;
    parameter FIRE_AES    = 3'b010;
    parameter WAIT_DONE   = 3'b011;
    parameter SEND_RESULT = 3'b100;
    parameter DONE        = 3'b101;
    
    reg [2:0] state = WAIT_KEY;

    assign RsTx = tx_serial_wire;
    assign led = { (state == DONE), aes_result[14:0] }; 

    // --- 3. Instantiations ---
    uart_rx #(.CLKS_PER_BIT(4)) receiver (
        .clk(sys_clk), .rx(RsRx), .data_out(rx_byte), .byte_ready(rx_ready)
    );

    uart_tx #(.CLKS_PER_BIT(4)) transmitter (
        .clk(sys_clk), .tx_start(tx_start), .data_in(tx_data), 
        .tx_serial(tx_serial_wire), .tx_busy(tx_busy)
    );

    aes_cipher_top  aes_core (
        .clk(sys_clk), .rst_n(~btnC), .start(aes_start), 
        .plaintext(text_reg),      
        .key(key_reg),
        .ciphertext(aes_result),   
        .done(aes_done)
    );

    reg aes_done_r = 0;

    always @(posedge sys_clk) begin
        aes_done_r <= aes_done;
    end

    // --- 4. Main Logic (Synchronous Reset Fix) ---
    always @(posedge sys_clk) begin
        if (btnC) begin
            state <= WAIT_KEY;
            byte_counter <= 0;
            aes_start <= 0;
            tx_start <= 0;
            tx_data <= 0;
            tx_substate <= 0;
            key_reg <= 0;
            text_reg <= 0;
        end else begin
            case (state)
                WAIT_KEY: begin
                    if (rx_ready) begin
                        key_reg <= {key_reg[119:0], rx_byte}; 
                        byte_counter <= byte_counter + 1;
                        if (byte_counter == 15) begin
                             byte_counter <= 0;
                             state <= WAIT_TEXT;
                        end
                    end
                end

                WAIT_TEXT: begin
                    if (rx_ready) begin
                        text_reg <= {text_reg[119:0], rx_byte}; 
                        byte_counter <= byte_counter + 1;
                        if (byte_counter == 15) begin
                            byte_counter <= 0;        // ← add this
                            state <= FIRE_AES;
                        end
                    end
                end

                FIRE_AES: begin
                    aes_start <= 1;
                    state     <= WAIT_DONE;
                end

                WAIT_DONE: begin
                    aes_start <= 0;
                    if (aes_done_r) begin     // use registered version — never miss it
                        byte_counter <= 0;
                        tx_substate  <= 0;
                        state        <= SEND_RESULT;
                    end
                end

                SEND_RESULT: begin
                    case (tx_substate)
                        0: begin 
                            if (!tx_busy) begin
                                tx_data <= aes_result[127 - (byte_counter * 8) -: 8];
                                tx_start <= 1;
                                tx_substate <= 1;
                            end
                        end
                        1: begin 
                            tx_start <= 0;
                            tx_substate <= 2;
                        end
                        2: begin 
                            if (!tx_busy) begin
                                if (byte_counter == 15) begin
                                    state <= DONE;
                                end else begin
                                    byte_counter <= byte_counter + 1;
                                    tx_substate <= 0; 
                                end
                            end
                        end
                    endcase
                end 
                
                DONE: begin
                    // Done
                end
                
                default: state <= WAIT_KEY;
            endcase
        end
    end

endmodule
module BUFG(input I, output O);
    assign O = I;
endmodule