// calcule nombres aléatoires

slave

:IP rdm $8010;
:IP rdm2 $8810;

PC s1 := { bamboozled put }

:bamboozled
0
xnum
=0
if
	$8000
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
	rdm2
else
	$8000
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
	rdm2
endif
;

start
master

: print
	7seg
	$1f
	btn
;

: main
begin
	s1
	wait
	S2M
	16
	->
	16
	->
	print
again
;

start 
	main
endprogram
