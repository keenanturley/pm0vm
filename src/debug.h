#ifndef DEBUG_H
#define DEBUG_H

/*
Debug Mode:
    If the debug_mode flag is set in a PM/0 machine, debug output will be
    printed to stdout in the following occasions:

    - After load() is called, the code that was loaded will be printed using
        print_assembly(), declared in this file. Additionally, the initial
        values of the machine will be printed.

    - After each step of the machine, the machine state will be printed with
        print_state(), also declared in this file.

*/

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

/*
Function: print_initial_values
    Prints the initial values of the machine.
    These include: PC, BP, and SP registers, all registers in the register
    file, and the stack values.
Parameters:
    p_machine * vm:
        The machine whose initial values will be printed
*/
void print_initial_values(p_machine * vm);

/*
Function: print_state
    Prints the current state of the machine.
    This includes: The next line of assembly code to be executed, the PC, BP,
    and SP registers, all registers in the register file, and the stack values.
Parameters:
    p_machine * vm:
        The machine whose initial values will be printed
*/
void print_state(p_machine * vm);

#endif /* DEBUG_H */
