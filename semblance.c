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
int PC;
int (*instruction_set[ISET_SIZE]) (struct command*);
int reg [NUM_REG];

/* Execute the code 
 * by iterating through `code` array
 * execute each command
 * */
void exec_code() {
    int info;
    for (PC = 1; PC < codesize; PC++) {
        info = (*instruction_set[code[PC].instr])(code+PC);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Correct usage is `semblance <filename>`\n");
        return 0;
    }
    code_file = fopen(argv[1], "r");
    read_file();
    printf("Finished reading file\n");
    for (int i = 1; i < 5; i++) {
        printf("%d\n", data[i]);
    }
    fclose(code_file);
    initialize_instruction_set();
    exec_code();
    return 0;
}
