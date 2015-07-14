#!/usr/bin/python3

import sys
comment_char = ';'
output = list()
codeline = 0
opcode_map = dict()
labels = dict()

def initialize_convert():
    opcode_map["iadd"]=10
    opcode_map["isub"]=11
    opcode_map["imul"]=12
    opcode_map["idiv"]=13
    opcode_map["imod"]=27
    opcode_map["load"]=14
    opcode_map["store"]=15
    opcode_map["andl"]=16
    opcode_map["orl"]=17
    opcode_map["eq"]=21
    opcode_map["jump"]=8
    opcode_map["jcon"]=9
    opcode_map["setr"]=20
    opcode_map["movr"]=19
    opcode_map["syscall"]=30
    opcode_map["exit"]=0 
    opcode_map["bpload"]=31
    opcode_map["bpstore"]=32
    opcode_map["call"]=33
    opcode_map["ret"]=34
    opcode_map["pushr"]=35
    opcode_map["popr"]=36
    opcode_map["addim"]=38
    opcode_map["subim"]=39
    opcode_map["retcon"]=40
    opcode_map["callcon"]=41
    
    opcode_map["pc"]=80
    opcode_map["sp"]=81
    opcode_map["bp"]=82
    
    opcode_map["sys0"]=90
    opcode_map["sys1"]=91
    opcode_map["sys2"]=92
    opcode_map["sys3"]=93
    
    opcode_map["printint"]=1 
    opcode_map["readint"]=10

def convert(w):
    if w in opcode_map:
        return str(opcode_map[w])
    if w[0]=='r' and int(w[1:]) < 20:
        return w[1:]
    if w[0]==':':
        return w #leave label reference untouched
    try:
        return str(int(w))
    except:
        print("INVALID SYNTAX: "+w)
        sys.exit(1)
#assume there's a var `line` with the current line
#check if line begins with a label
#if line.beginswith '_' (underscore) it is a label 
#get the label. labels[label] = (codeline-1)

#read next three strings: instr, operand1, operand2
#call convert() on each one and write the result to output_string
#label references like :bar are unchanged 
#on second pass, label references will be replaced with their number
def line_assemble(line):
    words = line.split()
    if words[0].startswith('_'):
        labels[words[0][1:]] = codeline-1
        words.pop(0)
    if len(words) > 3:
        print("Error: more than 3 on a line")
        sys.exit(1)
    elif len(words) < 1:
        print("Error: nothing on line")
        sys.exit(1)
    for w in words:
        output.append(convert(w)+' ')
    if len(words) < 2:
        output.append('0 ')
    if len(words) < 3:
        output.append('0')
    output.append('\n')
    
def second_pass(el):
    if el.startswith(':'):
        el = labels[el[1:].rstrip()]
        el = str(el)+' '
    return el
if len(sys.argv) == 3:
    initialize_convert()
    with open(sys.argv[1]) as file:
        for line in file:
            line = line.split(';')[0]
            if codeline == 0:
                output.append('0')
                output.append('\n')
            else:
                line_assemble(line)
            codeline += 1
    output = [second_pass(el) for el in output]
    with open(sys.argv[2], 'w') as out_file:
        out_file.write(''.join(output))
