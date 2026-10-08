`default_nettype none

module imem #(
  parameter int MEM_DEPTH = 1024,
  parameter string INIT_FILE = "program.hex"
  )
  (
    input wire [31:0] addr,
    output logic [31:0] inst
  );

  localparam int ADDR_W = $clog2(MEM_DEPTH);

  logic [31:0] mem [MEM_DEPTH];

  initial begin

    for(int i = 0; i < MEM_DEPTH; i++) begin
      mem[i] = 32'h0000_0013;
    end
    $readmemh(INIT_FILE, mem);

  end

  assign inst = mem[addr[ADDR_W+1:2]];

  endmodule

`default_nettype wire
