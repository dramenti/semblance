#Semblance

###Overview
Semblance is an assembly/machine code interpreter for compiling Jaysembly into Jaychine code.
Currently the jaychine code interpreter is functional. It is written in C.

Jaychine code consists of instructions of the form: (decimal integer) (decimal integer) (decimal integer)

First number is the instruction opcode, second two are operands.

The example program euclid is an implementation of Euclid's Algorithm.

###Usage
To use Semblance, first write the file in jaysembly.
Then do ./jaysembly.py [assembly] [output file name] output file doesn't need to exist beforehand.

To execute the compiled file, do ./semblance [output file name]

###Source description
* semblance.c: main file, contains instruction execution loop
* data.c: functions that read data from machine file, and create array of commands
* iset.c: the instruction set, implemented as array of pointers to instruction functions
* semcall.c: contains system call functions for printf and scanf
* globals.h: global variables
* jaysembly.py: the assembler written in Python

###To do
Right now, files have to start with .code on line 1 because .data
hasn't been implemented yet.
