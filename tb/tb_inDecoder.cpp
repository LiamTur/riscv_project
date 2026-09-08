
#include "VinDecoder.h"
#include "verilated.h"
#include <cstdio>


static int pass_count = 0;
static int fail_count = 0;

void funcchecker(VinDecoder top, uint8_t opcode, bool R, bool I, bool S, bool B, bool U, bool J){
      top->opcode = opcode;
      top->eval();
      bool R1 = (bool) top->R;
      bool I1 = (bool) top->I;
      bool S1 = (bool) top->S;
      bool B1 = (bool) top->B;
      bool U1 = (bool) top->U;
      bool J1 = (bool) top->J;
      if(R == R1 && I == I1 && S == S1 && B1 == B && U1 == U && J1 == J){
        printf("[PASS], R=%d I=%d S=%d B=%d U=%d J=%d d\n", name, rs1, rs2, actual);
        pass_count++;
      }else{
        printf("[PASS], R=%d I=%d S=%d B=%d U=%d J=%d d\n", name, rs1, rs2, actual);
        fail_count++;
      }
//
//      if(actual == expected){
//        printf("[PASS] %s: rs1=%d rs2=%d -> out=%d\n", name, rs1, rs2, actual);
//        pass_count++;
//      }else{
//        printf("[FAIL] %s: rs1=%d rs2=%d -> out=%d\n", name, rs1, rs2, actual);
//        fail_count++;
//      }
  }

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    VinDecoder* top = new VinDecoder{contextp};

    printf("\n%d passed, %d failed\n", pass_count, fail_count);


    delete top;
    delete contextp;
    return fail_count == 0 ? 0: 1;
}
