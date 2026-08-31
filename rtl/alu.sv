`default_nettype none


module alu

  import alu_pkg::*;
(
 input alu_op_e op_code,
 input wire [31:0] rs1,
 input wire [31:0] rs2,
 output logic [31:0] out,
 output logic z
);


alu_op_e alu_op;

assign alu_op = op_code;
assign z = (out == 32'b0);

always_comb begin
 case (alu_op)

ADD: begin
  out = rs1 + rs2;
end

SUB: begin
  out = rs1 - rs2;
end

SLL: begin
  out = rs1 << rs2[4:0];
end

STL: begin
  out = ((rs1[31] < rs2[31]) || (rs1[30:0] < rs2[30:0])) ? 1: 0;
end

STLU: begin
  out = (rs1 < rs2) ? 1: 0;
end

XOR: begin
  out = rs1 ^ rs2;
end

SRL: begin
  out = rs1 >> rs2[4:0];
end

SRA: begin
  out = $signed(rs1) >>> rs2[4:0];
end

OR: begin
  out = rs1 | rs2;
end

AND: begin
  out = rs1 & rs2;
  end

  default: begin
    out = '0;
  end
 endcase
 end


	endmodule
`default_nettype wire
