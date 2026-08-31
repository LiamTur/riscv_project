#include "Vnand_gate.h"
#include "verilated.h"

int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    Vnand_gate* top = new Vnand_gate{contextp};

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            top->A = a;
            top->B = b;
            top->eval();
            uint8_t expected = !(a & b);
            assert(top->C == expected);
        }
    }
    printf("All tests passed!\n");
    delete top;
    delete contextp;
    return 0;
}
