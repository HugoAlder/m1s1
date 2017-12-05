// calcule nombres aléatoires avec 2 processeurs en parallele

slave

// sans push
:IP rdm $8010;
// avec push
:IP rdm2 $8810;

PC myRdm := { rdm_s put put }

:rdm_s
0
xnum
=0
if
	// la moitie des tours de boucles, dans le premier esclave
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
	swap
else
	// l'autre moitie des tours de boucle, dans le second esclave
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
	swap
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
	all
	myRdm
	// barriere de synchro
	wait
	S2M
	comx
	S2M
	print
	// ajoute resultats des 2 procos
	add
	print
again
;

start 
	main
endprogram
