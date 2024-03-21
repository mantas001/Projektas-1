Testavimo sistemos parametrai:
RAM: 16GB, 3200 MHz
CPU: Processor	12th Gen Intel(R) Core(TM) i7-12650H, 2300 Mhz, 10 Core(s), 16 Logical Processor(s)
SSD: 
****************************************************************
Naudojant vector ir deque tipo konteinerius nuskaitymo, rikiavimo ir irasymo laikai beveik sutampa, o list tipo konteinerio laikai, palyginus su vector ir deque, gerokai isauga.

****************************************************************
vector konteineriai:

Nuskaityti 1000 irasu uztruko: 0.012904 s 
Surikiuoti 1000 irasu uztruko: 0.001041 s 
Irasyti    1000 irasu uztruko: 0.014665 s

Nuskaityti 10000 irasu uztruko: 0.096011 s 
Surikiuoti 10000 irasu uztruko: 0.007021 s 
Irasyti    10000 irasu uztruko: 0.088916 s

Nuskaityti 100000 irasu uztruko: 0.949501 s 
Surikiuoti 100000 irasu uztruko: 0.051738 s 
Irasyti    100000 irasu uztruko: 0.72446 s

Nuskaityti 1000000 irasu uztruko: 9.31908 s 
Surikiuoti 1000000 irasu uztruko: 0.538232 s
Irasyti    1000000 irasu uztruko: 6.82153 s

10mil. eil.:
terminate called after throwing an instance of 'std::bad_alloc' 
what(): std::bad_alloc

****************************************************************
deque konteineriai:

Nuskaityti 1000 irasu uztruko: 0.010996 s 
Surikiuoti 1000 irasu uztruko: 0.0011 s 
Irasyti    1000 irasu uztruko: 0.016981 s

Nuskaityti 10000 irasu uztruko: 0.095798 s
Surikiuoti 10000 irasu uztruko: 0.009556 s
Irasyti    10000 irasu uztruko: 0.072575 s

Nuskaityti 100000 irasu uztruko: 0.954725 s
Surikiuoti 100000 irasu uztruko: 0.068273 s
Irasyti    100000 irasu uztruko: 0.775124 s

Nuskaityti 1000000 irasu uztruko: 9.23689 s
Surikiuoti 1000000 irasu uztruko: 0.687518 s
Irasyti    1000000 irasu uztruko: 6.70069 s

10mil. eil.:
terminate called after throwing an instance of 'std::bad_alloc' 
what(): std::bad_alloc

****************************************************************
list konteineriai:

Nuskaityti 1000 irasu uztruko: 0.015074 s
Surikiuoti 1000 irasu uztruko: 0.003012 s
Irasyti    1000 irasu uztruko: 0.015409 s

Nuskaityti 10000 irasu uztruko: 0.152652 s
Surikiuoti 10000 irasu uztruko: 0.017703 s
Irasyti    10000 irasu uztruko: 0.312522 s

Nuskaityti 100000 irasu uztruko: 1.51064 s
Surikiuoti 100000 irasu uztruko: 0.162504 s
Irasyti    100000 irasu uztruko: 0.753468 s

Nuskaityti 1000000 irasu uztruko: 14.8636 s
Surikiuoti 1000000 irasu uztruko: 1.57861 s
Irasyti    1000000 irasu uztruko: 7.05502 s

10mil. eil.:
terminate called after throwing an instance of 'std::bad_alloc' 
what(): std::bad_alloc
****************************************************************