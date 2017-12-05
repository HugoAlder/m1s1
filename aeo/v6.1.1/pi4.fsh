// Pi Monte Carlo

slave 
start
master

:IP rdm $9010;
:IP square2 $c814;

: print
	7seg
	1
	btn
;

: main
0
	tic
	$10000
	begin
		dec
	    rdm

		square2
		$ffe001
		<=
		if
			swap
			inc
			swap
		endif
		dup
		=0
	until
drop
tic
dup
16
->
print
print
print
;

start 
	main
endprogram
