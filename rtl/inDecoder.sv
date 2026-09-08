`default_nettype none


module inDecoder
(
  input wire [6:0] opcode,
  output logic R,
  output logic I,
  output logic S,
  output logic B,
  output logic U,
  output logic J
);


//                      opcode 3, 2
//                    | 00 | 01 | 11 | 10 |
//                    +----+----+----+----+
// opcode 6,5,4   000 | I  | I  | I  | I  | 
//                    +----+----+----+----+
//                001 | I  | U  | U  |    | 
//                    +----+----+----+----+
//                011 | R  | U  | U  | R  | 
//                    +----+----+----+----+
//                010 | S  | S  | S  | S  | 
//                    +----+----+----+----+
//                110 | B  | I  | J  | J  | 
//                    +----+----+----+----+
//                111 | I  | I  | I  | I  | 
//                    +----+----+----+----+
//                101 | I  | I  | I  | I  | 
//                    +----+----+----+----+
//                100 | I  | I  | I  | I  | 
//                    +----+----+----+----+
//
//                    S: opcode [6,5,4] == 010
//                    U: opcode [6,4,2] == 011
//                    R: opcode [6,5,4,2] == 0110
//                    B: opcode == 11000
//                    J: opcode [6,5,4,3] == 1101
//                    I: opcode[5,4] == 00 || opcode [6,4] == 11 || opcode [6,
//                    3,2] == 101 || opcode [5,3,2] == 000


assign S = {opcode[6:4]} == 3'b010;
assign U = {opcode[6], opcode[4], opcode[2]} == 3'b011;
assign R = {opcode[6:4], opcode[2]} == 4'b0110;
assign B = opcode[6:2] == 5'b11000;
assign J = opcode[6:3] == 4'b1101;
assign I = opcode[5:4] == 2'b00 
          | {opcode[6], opcode[4]} == 2'b11 
          | {opcode[6], opcode[3:2]} == 3'b101 
          | {opcode[5], opcode[3:2]} == 3'b000;

endmodule
`default_nettype none
