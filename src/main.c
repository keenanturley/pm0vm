/*
Author: Keenan Turley <keenan.turley@knights.ucf.edu>
Date: 2020-01-27
Course: COP3402 - Systems Software
Assignment: Homework #1 (P-Machine)
*/

#include <stdio.h>
#include <stdlib.h>
#include "pm0.h"
#include "loader.h"
#include "debug.h"

int main(int argc, char ** argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: ./pm0vm <file-path>\n");
        return EXIT_FAILURE;
    }

    p_machine * vm = create_machine();
    load(argv[1], vm);

    print_assembly(vm);

    run(vm);

    vm = destroy(vm);
    return EXIT_SUCCESS;
}
