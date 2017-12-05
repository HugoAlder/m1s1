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
	$10000
	for
		rdm
		dup
		12
		->
		$FFF
		and
		swap
		$FFF
		and

		dup
		mul16
		swap
		dup
		mul16
		add
		$FFE001
		<=
		1
		and
		add
	next

print
;

start
	main
endprogram