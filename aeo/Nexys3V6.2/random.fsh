// calcule nombres aléatoires

slave 
start
master

:IP rdm $8810;
:IP rdm2 $8010;

: main
begin
	$1f
	btn
	48
	for
		rdm2
	next
	rdm
	7seg
again
;

start 
	main
endprogram
