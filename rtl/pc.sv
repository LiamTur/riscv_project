`default_nettype none

module pc ( 
  input  wire         clk,
  input  wire         rst_n,
  input  wire [31:0]  immediate,
  input  wire         jalr,
  input  wire [31:0]  alu_out,
  output logic [31:0] pc
  );

  logic pc [31:0];

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n)begin
      pc <= '0;
    end
    else begin
      if (jalr) begin
        pc <= {alu_out[31:1], 1'b0};
      end
      else begin
        pc <= pc + 32'd4;
      end
    end
  end


  endmodule

`default_nettype wire
