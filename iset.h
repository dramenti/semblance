#ifndef ISET_H
#define ISET_H
#include "globals.h"

int iadd (struct command *cmd);
int isub (struct command *cmd);
int imul (struct command *cmd);
int idiv (struct command *cmd);
int imod (struct command *cmd);
int load (struct command *cmd);
int store (struct command *cmd);
int andl (struct command *cmd);
int orl (struct command *cmd);
//int XOR (struct command *cmd);
int eq (struct command *cmd);
int neq (struct command *cmd);
int jump (struct command *cmd);
int jcon (struct command *cmd);
int setr (struct command *cmd);
int movr (struct command *cmd);
int scall (struct command *cmd);
int bpload (struct command *cmd);
int bpstore (struct command *cmd);
int call (struct command *cmd);
int ret (struct command *cmd);
int pushr (struct command *cmd);
int popr (struct command *cmd);
int addim (struct command *cmd);
int subim (struct command *cmd);
int end (struct command *cmd);
/* maps opcodes to function pointers */
void initialize_instruction_set();

#endif
