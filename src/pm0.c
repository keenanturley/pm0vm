#include "pm0.h"
#include <stdlib.h>

p_machine * create_machine() {
    p_machine * vm = (p_machine *)malloc(sizeof(p_machine));
    vm->SP = 0;
    vm->BP = 1;
    vm->PC = 0;

    vm->IR.l = vm->IR.m = vm->IR.op = vm->IR.r = 0;

    for (int i = 0; i < NUM_REGISTERS; i++) {
        vm->RF[i] = 0;
    }

    for (int i = 0; i < MAX_STACK_HEIGHT; i++) {
        vm->stack[i] = 0;
    }

    return vm;
}
