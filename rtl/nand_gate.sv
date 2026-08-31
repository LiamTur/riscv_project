`default_nettype none

module nand_gate(
	input wire A,
	input wire B,
	output logic C
	);

	assign C = ~(A & B);

endmodule


`default_nettype wire
