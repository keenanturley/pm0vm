#include <stdio.h>
#include "debug.h"

const char * OPERATOR_NAMES[] = {
    "lit", "rtn", "lod", "sto", "cal", "inc", "jmp", "jpc",
    "sio", "sio", "sio", "neg", "add", "sub", "mul", "div",
    "odd", "mod", "eql", "neq", "lss", "leq", "gtr", "geq" };

void print_assembly(p_machine * vm) {
    // Headers
    printf("Line\tOP\tR\tL\tM\n");
    instruction * ins;
    for (int i = 0; i < vm->code_length; i++) {
        ins = &(vm->code[i]);
        printf("%d\t%s\t%d\t%d\t%d\n", i, OPERATOR_NAMES[ins->op - 1],
            ins->r, ins->l, ins->m);
    }
}
