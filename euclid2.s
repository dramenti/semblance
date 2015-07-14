.code
jump :main
_gcd setr r3 0
eq r3 r2
retcon r3
movr r4 r1
movr r1 r2
imod r4 r2
movr r2 r4
jump :gcd
_main syscall readint
movr r1 sys1
syscall readint
movr r2 sys1
call :gcd
movr sys0 r1
syscall printint
exit