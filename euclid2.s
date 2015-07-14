.code
jump :main ;begin program
_gcd setr r3 0 ;set register 3 to 0
eq r3 r2 ; check if b == 0
retcon r3 ; if b == 0 then return a (register 1)
movr r4 r1 ; otherwise do a, b = b, a%b
movr r1 r2
imod r4 r2
movr r2 r4
jump :gcd ; call gcd again, use jump as tail-recursion to save memory
_main syscall readint ; read user input into sys1 register
movr r1 sys1 ; move user input into r1, repeat
syscall readint
movr r2 sys1
call :gcd ; call gcd with args r1, r2
movr sys0 r1 ; move value to print into sys0 register
syscall printint ; prints content of sys0 register
exit ; done
