module aes_top_spartan6 (
    input  wire        clk_in,     // board clock (typically 50MHz)
    input  wire        rst_btn,    // active-high pushbutton
    // Input via switches/UART — for now use fixed test vector
    input  wire        start_btn,
    output wire [7:0]  led,        // status LEDs
    output wire        done_led
);

    wire clk;
    wire locked;

    // DCM for clock management
    DCM_SP #(
        .CLKDV_DIVIDE      (2.0),
        .CLKFX_DIVIDE      (1),
        .CLKFX_MULTIPLY    (2),
        .CLKIN_DIVIDE_BY_2 ("FALSE"),
        .CLKIN_PERIOD      (20.0),   // 50 MHz input
        .CLKOUT_PHASE_SHIFT("NONE"),
        .CLK_FEEDBACK      ("1X"),
        .DESKEW_ADJUST     ("SYSTEM_SYNCHRONOUS"),
        .STARTUP_WAIT      ("FALSE")
    ) dcm_inst (
        .CLKIN   (clk_in),
        .CLKFB   (clk),
        .CLK0    (clk),
        .LOCKED  (locked),
        .RST     (1'b0)
    );

    // Reset synchronizer
    reg [3:0] rst_sr = 4'hF;
    always @(posedge clk)
        rst_sr <= {rst_sr[2:0], rst_btn | ~locked};
    wire rst_n = ~rst_sr[3];

    // Start button debouncer
    reg [19:0] dbnc_cnt  = 0;
    reg        start_r   = 0;
    reg        start_prev= 0;
    reg        start_pulse;

    always @(posedge clk) begin
        start_prev <= start_r;
        if (dbnc_cnt == 20'hFFFFF)
            start_r <= start_btn;
        else
            dbnc_cnt <= dbnc_cnt + 1;
        start_pulse <= start_r & ~start_prev;
    end

    // AES core
    wire [127:0] ciphertext;
    wire         done;

    aes_cipher_top aes_core (
        .clk       (clk),
        .rst_n     (rst_n),
        .start     (start_pulse),
        .plaintext (128'h3243f6a8885a308d313198a2e0370734),
        .key       (128'h2b7e151628aed2a6abf7158809cf4f3c),
        .ciphertext(ciphertext),
        .done      (done)
    );

    // Show lower 8 bits of ciphertext on LEDs
    assign led     = ciphertext[7:0];
    assign done_led = done;

endmodule