`default_nettype none

module dmem #(
  parameter int MEM_DEPTH = 1024
) (
  input  wire         clk,
  input  wire         we,
  input  wire  [3:0]  be,        // byte enables: be[0] = bits 7:0, etc.
  input  wire  [31:0] addr,
  input  wire  [31:0] i_data,
  output logic [31:0] o_data
);

  localparam int ADDR_W = $clog2(MEM_DEPTH);

  logic [31:0] mem [MEM_DEPTH];

  initial begin
    for (int i = 0; i < MEM_DEPTH; i++) mem[i] = 32'h0000_0000;
  end

  wire [ADDR_W-1:0] word_addr = addr[ADDR_W+1:2];

  // Write: per-byte enables
  always_ff @(posedge clk) begin
    if (we) begin
      if (be[0]) mem[word_addr][ 7: 0] <= i_data[ 7: 0];
      if (be[1]) mem[word_addr][15: 8] <= i_data[15: 8];
      if (be[2]) mem[word_addr][23:16] <= i_data[23:16];
      if (be[3]) mem[word_addr][31:24] <= i_data[31:24];
    end
  end

  // Read: combinational (single-cycle core)
  assign o_data = mem[word_addr];

endmodule

`default_nettype wire
