// Fibo

slave
start
master

: print
	7seg
	1
	btn
;

: read8
	$1f
	btn
	switch

: main
1
1
read8
ticraz
for
	dup
	rot
	add
next
tic
print*
print
;

start
	main
endprogram
