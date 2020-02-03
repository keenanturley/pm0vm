/*
Authors: Keenan Turley <keenan.turley@knights.ucf.edu>
         Alexander Desmond <alexdesmond@knights.ucf.edu>
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
    // Handle invalid program arguments
    if (argc != 2) {
        fprintf(stderr, "usage: ./pm0vm (file-path)\n");
        return EXIT_FAILURE;
    }

    // Create the machine
    p_machine * vm = create_machine();

    // Turn debug mode on
    vm->debug_mode = 1;

    // Load the given source file into the machine
    load(argv[1], vm);

    // Run the machine until halt
    run(vm);

    // Destroy the machine after we're done with it
    vm = destroy(vm);

    return EXIT_SUCCESS;
}
