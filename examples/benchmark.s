.code
jump :main
_main setr r1 0
setr r3 10000000
_loop1 addim r1 1 ;loop iterates while r1 != r3
movr r2 r3
neq r2 r1
jcon :loop1 r2
movr sys0 r1
syscall printint
exit
