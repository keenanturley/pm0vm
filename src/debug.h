#ifndef DEBUG_H
#define DEBUG_H

#include "pm0.h"

/*
Array of operator names for assembly conversion.
Use: OPERATOR_NAMES[opcode - 1]  = opcode name
Example: OPERATOR_NAMES[4] == "CAL" (CAL's opcode is 5)
*/
extern const char * OPERATOR_NAMES[];

/*
Function: print_assembly
    Prints the vm's code in a tab delimited formatted list as assebly with the
    following columns: Line (line number in source code), OP (string
    representation of op code), R, L, and M.
Parameters:
    p_machine * vm:
        The machine whose code will be printed
*/
void print_assembly(p_machine * vm);

#endif /* DEBUG_H */
