// Fibo

slave
start
master

:IP fibobus $ac03;

: print
	7seg
	$1f
	btn
;

: read8
	$1f
	btn
	switch
;

: main
begin
  read8
  1
  minus
  fibobus
  print
again
;

start
	main
endprogram

//1 2 3 4 5 6 7  8
//1 1 2 3 5 8 13 21
