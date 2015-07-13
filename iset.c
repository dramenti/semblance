#include "iset.h"

int iadd (struct command *cmd) {
    // OP1 <-- OP1 + OP2
    reg[cmd->operand1] += reg[cmd->operand2];
    return 0;
}

int isub (struct command *cmd) {
    // OP1 <-- OP1 - OP2
    reg[cmd->operand1] -= reg[cmd->operand2];
    return 0;
}

int imul (struct command *cmd) {
    // OP1 <-- OP1 * OP2
    reg[cmd->operand1] *= reg[cmd->operand2];
    return 0;
}

int idiv (struct command *cmd) {
    // OP1 <-- OP1 / OP2
    reg[cmd->operand1] /= reg[cmd->operand2];
    return 0;
}

int imod (struct command *cmd) {
    // OP1 <-- OP1 % OP2
    reg[cmd->operand1] %= reg[cmd->operand2];
    return 0;
}
int load (struct command *cmd) {
    //load data value into register
    reg[cmd->operand1] = data[cmd->operand2];
    return 0;
}
int store (struct command *cmd) {
    data[cmd->operand1] = reg[cmd->operand2];
    return 0;
}
int andl (struct command *cmd) {
    // OP1 <-- OP1 && OP2 
    reg[cmd->operand1] = reg[cmd->operand1] && reg[cmd->operand2];
    return 0;
}
int orl (struct command *cmd) {
    // OP1 <-- OP1 || OP2 
    reg[cmd->operand1] = reg[cmd->operand1] || reg[cmd->operand2];
    return 0;
}

int eq (struct command *cmd) {
    //OP1 <-- OP1 == OP2 
    reg[cmd->operand1] = (reg[cmd->operand1] == reg[cmd->operand2]);
    return 0;
}
int neq (struct command *cmd) {
    //OP1 <-- OP1 != OP2
    reg[cmd->operand1] = (reg[cmd->operand1] != reg[cmd->operand2]);
    return 0;
}

int jump (struct command *cmd) {
    PC = cmd->operand1;
    return 0;
}
int jcon (struct command *cmd) {
    if (reg[cmd->operand2]) {
        PC = cmd->operand1;
    }
    return 0;
}
int setr (struct command *cmd) {
    // OP1 <-- immediate OP2
    reg[cmd->operand1] = cmd->operand2;
    return 0;
}

int movr (struct command *cmd) {
    // OP1 <-- OP2
    reg[cmd->operand1] = reg[cmd->operand2];
    return 0;
}
int end (struct command *cmd) {
    return 1;
}

void initialize_instruction_set() {
    instruction_set[10] = iadd;
    instruction_set[11] = isub;
    instruction_set[12] = imul;
    instruction_set[13] = idiv;
    instruction_set[27] = imod;
    instruction_set[14] = load;
    instruction_set[15] = store;
    instruction_set[16] = andl;
    instruction_set[17] = orl;
    instruction_set[21] = eq;
    instruction_set[8] = jump;
    instruction_set[9] = jcon;
    instruction_set[20] = setr;
    instruction_set[19] = movr;
    instruction_set[0] = end;
    /*instruction_set[]
    instruction_set[]
    instruction_set[]
    instruction_set[]
    instruction_set[]
    instruction_set[]
    instruction_set[]*/
}
