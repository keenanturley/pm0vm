#ifndef LOADER_H
#define LOADER_H

#include "pm0.h"

/*
Function: parse_instruction
    Parses and places the instruction segments from a given string into the
    instruction structure pointed to by i.
Parameters:
    char * line: The line to read an instruction from
    instruction * i: A pointer to the instruction to write values to
Note:
    The line should be composed as a sequence of 4 integers, compliant with
    the PM/0 specification, each separated by a single space character.
*/
void parse_instruction(char * line, instruction * i);

/*
Function: load
    Attempts to load the instructions included in the given file into the
    code memory of the given vm.
Parameters:
    char * file_path:
        The path to a file containing assembly instructions in integer form
    p_machine * vm:
        The machine to load instructions into
*/
void load(char * file_path, p_machine * vm);

#endif /* LOADER_H */
