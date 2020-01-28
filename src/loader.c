#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "loader.h"
#include "debug.h"

void parse_instruction(char * line, instruction * i) {
    char * op = strtok(line, " ");
    char * r  = strtok(NULL, " ");
    char * l  = strtok(NULL, " ");
    char * m  = strtok(NULL, " ");

    if (op == NULL || r == NULL || l == NULL || m == NULL) {
        fprintf(stderr, "Invalid instruction format, exiting...\n");
        exit(EXIT_FAILURE);
    }

    i->op = atoi(op);
    i->r  = atoi(r);
    i->l  = atoi(l);
    i->m  = atoi(m);
}

void load(char * file_path, p_machine * vm) {
    FILE * fp = fopen(file_path, "r");
    char * line = NULL;
    size_t n = 0;
    int line_num = 0;

    while (getline(&line, &n, fp) != -1) {
        parse_instruction(line, &(vm->code[line_num]));
        vm->code[line_num].line_number = line_num;
        line_num++;
    }

    vm->code_length = line_num;

    if (line) {
        free(line);
    }

    fclose(fp);

    if (vm->debug_mode) {
        print_assembly(vm);
        print_initial_values(vm);
    }
}
