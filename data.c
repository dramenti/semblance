#include <stdbool.h>
#include <stdio.h>
#include "data.h"
#include "globals.h"

void read_file() {
    read_data();
    read_code();
}

/* Read each line, storing variables
 * into data
 * */
void read_data() {
    int address = 0;
    int value = 0;
    while (true) {
        fscanf(code_file, "%d", &address);
        //printf("%d", address);
        if (address == 0) return; //0 signifies start of program
        fscanf(code_file, "%d", &value);
        //address, value is ready to be stored into data
        data[address] = value;
    }
}

void read_code() {
    struct command next_command;
    int i = 1;
    while (fscanf(code_file, "%d", &next_command.instr) != EOF) {
        fscanf(code_file, "%d", &next_command.operand1);
        fscanf(code_file, "%d", &next_command.operand2);
        code[i] = next_command;
        i++;
    }
    codesize = i;
}
