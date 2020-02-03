#include <stdio.h>
#include "debug.h"

const char * OPERATOR_NAMES[] = {
    "lit", "rtn", "lod", "sto", "cal", "inc", "jmp", "jpc",
    "sio", "sio", "sio", "neg", "add", "sub", "mul", "div",
    "odd", "mod", "eql", "neq", "lss", "leq", "gtr", "geq" };

void print_assembly(p_machine * vm) {
    // Headers
    printf("Line  OP   R  L  M\n");
    instruction * ins;
    for (int i = 0; i < vm->code_length; i++) {
        ins = &(vm->code[i]);
        printf("%-4d  %-3s  %1d  %1d  %d\n", i, OPERATOR_NAMES[ins->op - 1],
            ins->r, ins->l, ins->m);
    }
    printf("\n");
}

void print_initial_values(p_machine * vm) {
    printf("%20c  %-4s    %-4s    %-5s   %s\n", ' ', "pc", "bp", "sp", "registers");

    printf("%-20s  %-4d    %-4d    %-4d    ", "Initial values", vm->PC, vm->BP, vm->SP);
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
    printf("%-4d%-5s%-2d %-2d %-7d", vm->IR.line_number,
        OPERATOR_NAMES[vm->IR.op - 1], vm->IR.r, vm->IR.l, vm->IR.m);
    printf("%-8d%-8d%-8d", vm->PC, vm->BP, vm->SP);
    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("%d ", vm->RF[i]);
    }
    printf("\n");

    printf("Stack: ");
    for (int i = 1; i <= vm->SP && i < MAX_STACK_HEIGHT; i++) {
        if(vm->AR[i] == 1){
            printf("| ");
        }
        printf("%d ", vm->stack[i]);
    }
    printf("\n\n");
}
