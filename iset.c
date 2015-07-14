#include "iset.h"
#include "semcall.h"

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
    reg[PC_loc] = cmd->operand1;
    return 0;
}
int jcon (struct command *cmd) {
    if (reg[cmd->operand2]) {
        reg[PC_loc] = cmd->operand1;
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

int scall (struct command *cmd) {
    semcall(cmd->operand1);
    return 0;
}
int bpload (struct command *cmd) {
    reg[cmd->operand1] = data[reg[BP_loc]+cmd->operand2]; //offset from BP
    return 0;
}

int bpstore (struct command *cmd) {
    data[reg[BP_loc]+cmd->operand1] = reg[cmd->operand1];
    return 0;
}

int call (struct command *cmd) {
    reg[SP_loc]++;
    data[reg[SP_loc]] = reg[PC_loc];
    reg[PC_loc] = cmd->operand1;
    return 0;
}

int ret (struct command *cmd) {
    reg[PC_loc] = data[reg[SP_loc]];
    reg[SP_loc]--;
    return 0;
}

int pushr (struct command *cmd) {
    reg[SP_loc]++;
    data[reg[SP_loc]] = reg[cmd->operand1];
    return 0;
}

int popr (struct command *cmd) {
    reg[cmd->operand1] = data[reg[SP_loc]];
    reg[SP_loc]--;
    return 0;
}

int addim (struct command *cmd) {
    reg[cmd->operand1] += cmd->operand2;
    return 0;
}

int subim (struct command *cmd) {
    reg[cmd->operand1] -= cmd->operand2;
    return 0;
}

int retcon (struct command *cmd) {
    if (reg[cmd->operand1])
        ret(cmd);
    return 0;
}

int callcon (struct command *cmd) {
    if (reg[cmd->operand2])
        call(cmd);
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
    instruction_set[30] = scall;
    instruction_set[0] = end;
    instruction_set[31] = bpload;
    instruction_set[32] = bpstore;
    instruction_set[33] = call;
    instruction_set[34] = ret;
    instruction_set[35] = pushr;
    instruction_set[36] = popr;
    instruction_set[38] = addim;
    instruction_set[39] = subim;
    instruction_set[40] = retcon;
    instruction_set[41] = callcon;
    /*instruction_set[]*/
}
