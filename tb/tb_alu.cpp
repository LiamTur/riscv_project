#include "Valu.h"
#include "verilated.h"
#include <cstdio>

enum AluOp : uint8_t {
    ALU_ADD = 0, ALU_SUB = 1, ALU_SLL = 2, ALU_SLT = 3, ALU_SLTU = 4,
    ALU_XOR = 5, ALU_SRL = 6, ALU_SRA = 7, ALU_OR = 8, ALU_AND = 9
};

static int pass_count = 0;
static int fail_count = 0;

void funcchecker(int32_t rs1, int32_t rs2, Valu* top, AluOp opcode, const char* name, int32_t expected){
      top->rs1 = rs1;
      top->rs2 = rs2;
      top->op_code = opcode;
      top->eval();
      int32_t actual = (int32_t) top->out;

      if(actual == expected){
        printf("[PASS] %s: rs1=%d rs2=%d -> out=%d\n", name, rs1, rs2, actual);
        pass_count++;
      }else{
        printf("[FAIL] %s: rs1=%d rs2=%d -> out=%d\n", name, rs1, rs2, actual);
        fail_count++;
      }
  }

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    Valu* top = new Valu{contextp};

    funcchecker(10, 3, top, ALU_ADD, "ADD", 13);
    funcchecker(10, 3, top, ALU_SUB, "SUB", 7);
    funcchecker(10, 1, top, ALU_SLL, "SLL", 20);
    funcchecker(10, 1, top, ALU_SLT, "SLT", 0);
    funcchecker(10, 1, top, ALU_SLTU, "SLTU", 0);
    funcchecker(2,  1, top, ALU_XOR, "XOR", 3);
    funcchecker(10, 1, top, ALU_SRL, "SRL", 5);
    funcchecker(-10, 1, top, ALU_SRA, "SRA", -5);
    funcchecker(1,  1, top, ALU_OR,  "OR",  1);
    funcchecker(1,  1, top, ALU_AND, "AND", 1);


    printf("\n%d passed, %d failed\n", pass_count, fail_count);


    delete top;
    delete contextp;
    return fail_count == 0 ? 0: 1;
}
