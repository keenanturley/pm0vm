#ifndef PM0_H
#define PM0_H

/* Constants */
#define MAX_STACK_HEIGHT 40
#define MAX_CODE_LENGTH 200
#define MAX_LEXI_LEVELS 3
#define NUM_REGISTERS 8


typedef struct instruction {
    int op;
    int r;
    int l;
    int m;

    int line_number;
} instruction;

typedef struct p_machine {
    /* Registers */
    int BP; /* Base Pointer */
    int SP; /* Stack Pointer */
    int PC; /* Program Counter */
    instruction IR; /* Instruction Register */
    int RF[NUM_REGISTERS]; /* Regsiter File */

    int stack[MAX_STACK_HEIGHT];
    instruction code[MAX_CODE_LENGTH];

    int halt; /* Halt flag */
    int code_length; /* Current code length */
    int debug_mode; /* Debug mode flag*/
    int AR[MAX_STACK_HEIGHT];
} p_machine;

/*
Function: create_machine
    Dynamically allocates space for a PM/0 virtual machine and initializes
    the appropriate values within.

Returns: struct p_machine *
    A pointer to the dynamically allocated virtual machine.
*/
struct p_machine * create_machine();

/*
Function: fetch
    Fetches an instruction from the code memory and increments the program
    counter.
Parameters:
    p_machine * vm:
        The machine to fetch an instruction on
Note:
    This is the first cycle in the PM/0 machine, followed only by the execute
    cycle.
*/
void fetch(p_machine * vm);

/*
Function: execute
    Executes the instruction that was fetched according to the PM/0
    specification.
Parameters:
    p_machine * vm:
        The machine to execute an instruction on
*/
void execute(p_machine * vm);

/*
Function: step
    Steps through one cycle (fetch + execute) of the given PM/0 machine.
Parameters:
    p_machine * vm:
        The PM/0 machine to make a step in
*/
void step(p_machine * vm);

/*
Function: run
    Begins the p-machine cycles, fetching and executing instructions
    until either the end of the program is indicated by an instruction or
    the code array has been exhausted.
Parameters:
    p_machine * vm:
        The machine to run
*/
void run(p_machine * vm);

/*
Function: base
    Get the base pointer of the stack from l levels below
Parameters:
    p_machine * vm:
        The machine whos base pointer to use
    int l:
        The amount of levels to traverse down
*/
int base(p_machine * vm, int l);

/*
Function: destroy
    Destroys (frees) the given machine. Caller should set the vm to the
    return value of this function to prevent use after free errors.
Parameters:
    p_machine * vm:
        The machine to destroy
Returns: p_machine *
    A null pointer
*/
p_machine * destroy(p_machine * vm);

#endif /* PM0_H */
