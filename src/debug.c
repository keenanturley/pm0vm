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
    printf("\n");
}

void print_initial_values(p_machine * vm) {
    printf("\t\tpc\tbp\tsp\tregisters\n");

    printf("Initial values\t%d\t%d\t%d\t", vm->PC, vm->BP, vm->SP);
    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("%d ", vm->RF[i]);
    }
    printf("\n");

    printf("Stack: ");
    for (int i = 1; i < MAX_STACK_HEIGHT; i++) {
        printf("%d ", vm->stack[i]);
    }
    printf("\n\n");
}

void print_state(p_machine * vm) {
    printf("%2d %s %d %d %d\t", vm->IR.line_number,
        OPERATOR_NAMES[vm->IR.op - 1], vm->IR.r, vm->IR.l, vm->IR.m);
    printf("%d\t%d\t%d\t", vm->PC, vm->BP, vm->SP);
    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("%d ", vm->RF[i]);
    }
    printf("\n");

    printf("Stack: ");
    for (int i = 1; i < vm->SP; i++) {
        printf("%d ", vm->stack[i]);
    }
    printf("\n\n");
}
