#ifndef GLOBALS_H
#define GLOBALS_H
#define MAX_DATA_SIZE 2000
#define MAX_CODE_SIZE 1000
#define NUM_REG 100
#define ISET_SIZE 100
#include <stdio.h>


struct command {
    int instr;
    int operand1;
    int operand2;
};

//typedef int (*instr_f_ptr) (struct command*);

extern int (*instruction_set[ISET_SIZE]) (struct command*);

/* Code */
extern struct command code [MAX_CODE_SIZE];

/* Program Counter (PC) keeps track of index in code */
extern int PC_loc;

/* Stack Pointer (SP) keeps track of the top of the datastack 
 * Base Pointer (BP) keeps track of the bottom of the datastack */

extern int SP_loc;
extern int BP_loc;

/* codesize: number of commands in code*/
extern int codesize;

/* Code file*/
extern FILE *code_file;

/* Memory (static data and the stack)
 * For now stack grows upwards because easier to implement */
extern int data [MAX_DATA_SIZE];


/* Standard registers */
extern int reg [NUM_REG];

#endif
