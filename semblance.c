#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data.h"
#include "globals.h"
#include "iset.h"

struct command code [MAX_CODE_SIZE];
FILE *code_file;
int data [MAX_DATA_SIZE];
int codesize;
int PC_loc = 80;
int SP_loc = 81;
int BP_loc = 82;

int (*instruction_set[ISET_SIZE]) (struct command*);
int reg [NUM_REG];

/* Execute the code 
 * by iterating through `code` array
 * execute each command
 * */
void exec_code() {
    int info;
    for (reg[PC_loc] = 1; reg[PC_loc] < codesize; reg[PC_loc]++) {
        info = (*instruction_set[code[reg[PC_loc]].instr])(code+reg[PC_loc]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Correct usage is `semblance <filename>`\n");
        return 0;
    }
    code_file = fopen(argv[1], "r");
    read_file();
/*    printf("Finished reading file\n");
    for (int i = 1; i < 5; i++) {
        printf("%d\n", data[i]);
    }*/
    fclose(code_file);
    initialize_instruction_set();
    exec_code();
    return 0;
}
