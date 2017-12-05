// Pi Monte Carlo

slave 
start
master

:IP rdm $8810;

: print
	7seg
	1
	btn
;

: main
0
	ticraz
	$10000
	for 
	    rdm
	    dup
	    12
	    ->
	    $fff
	    and
	    swap
	    $fff
	    and

		dup
		mul16
		swap
		dup
		mul16
		add
		$ffe001
		<=
		if
			inc
		endif
	next
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
