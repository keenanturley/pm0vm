#include <stdlib.h>
#include <stdio.h>
#include "pm0.h"

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

    vm->halt = 0;

    return vm;
}

void fetch(p_machine * vm) {
    vm->IR = vm->code[vm->PC];
    vm->PC++;
}

void execute(p_machine * vm) {
    instruction * i = &(vm->IR);
    switch (i->op) {
        case 1: // LIT - load immediate to register
            vm->RF[i->r] = i->m;
            break;
        case 2: // RTN - return from subroutine
            vm->SP = vm->BP - 1;
            vm->BP = vm->stack[vm->SP + 3];
            vm->PC = vm->stack[vm->SP + 4];
            break;
        case 3: // LOD - load value into register from stack
            vm->RF[i->r] = vm->stack[base(vm, i->l) + i->m];
            break;
        case 4: // STO - store value from register in stack
            vm->stack[base(vm, i->l) + i->m] = vm->RF[i->r];
            break;
        case 5: // CAL - call procedure at m
            vm->stack[vm->SP + 1] = 0; // return value
            vm->stack[vm->SP + 2] = base(vm, i->l);
            vm->stack[vm->SP + 3] = vm->BP;
            vm->stack[vm->SP + 4] = vm->PC;
            vm->BP = vm->SP + 1;
            vm->PC = i->m;
            break;
        case 6: // INC - increment SP by M (allocating locals)
            vm->SP = vm->SP + i->m;
            break;
        case 7: // JMP - jump to instruction m
            vm->PC = i->m;
            break;
        case 8: // JPC - Jump to m if register has 0
            if (vm->RF == 0)
                vm->PC = i->m;
            break;
        case 9: // SIO - Write register to screen
            printf("%d\n", vm->RF[i->r]);
            break;
        case 10: // SIO - Read user input into register
            scanf("%d", &(vm->RF[i->r]));
            break;
        case 11: // SIO - halt / end of program
            vm->halt = 1;
            break;
        case 12: // NEG - RF[r] = -RF[l]
            vm->RF[i->r] = -(vm->RF[i->l]);
            break;
        case 13: // ADD - RF[r] = RF[l] + RF[m]
            vm->RF[i->r] = vm->RF[i->l] + vm->RF[i->m];
            break;
        case 14: // SUB - RF[r] = RF[l] - RF[m]
            vm->RF[i->r] = vm->RF[i->l] - vm->RF[i->m];
            break;
        case 15: // MUL - RF[r] = RF[l] * RF[m]
            vm->RF[i->r] = vm->RF[i->l] * vm->RF[i->m];
            break;
        case 16: // DIV - RF[r] = RF[l] / RF[m]
            vm->RF[i->r] = vm->RF[i->l] / vm->RF[i->m];
            break;
        case 17: // ODD - RF[r] = RF[r] mod 2
            vm->RF[i->r] = vm->RF[i->r] % 2;
            break;
        case 18: // MOD - RF[r] = RF[l] mod RF[m]
            vm->RF[i->r] = vm->RF[i->l] % vm->RF[i->m];
            break;
        case 19: // EQL - RF[r] = RF[l] == RF[m]
            vm->RF[i->r] = (vm->RF[i->l] == vm->RF[i->m]);
            break;
        case 20: // NEQ - RF[r] = RF[l] != RF[m]
            vm->RF[i->r] = (vm->RF[i->l] != vm->RF[i->m]);
            break;
        case 21: // LSS - less than
            vm->RF[i->r] = (vm->RF[i->l] < vm->RF[i->m]);
            break;
        case 22: // LEQ - less than or equal to
            vm->RF[i->r] = (vm->RF[i->l] <= vm->RF[i->m]);
            break;
        case 23: // GTR - greater than
            vm->RF[i->r] = (vm->RF[i->l] > vm->RF[i->m]);
            break;
        case 24: // GEQ - greater than or equal to
            vm->RF[i->r] = (vm->RF[i->l] >= vm->RF[i->m]);
            break;
    }
}

void run(p_machine * vm) {
    for (int i = 0; i < MAX_CODE_LENGTH && vm->halt == 0; i++) {
        fetch(vm);
        execute(vm);
    }
}

int base(p_machine * vm, int l) {
    int b1;
    b1 = vm->BP;
    while(l > 0) {
        b1 = vm->stack[b1 + 1];
        l--;
    }
    return b1;
}
