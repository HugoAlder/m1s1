// addition 16 bits 

slave 
start
master

: read16
	$1f
	btn
	switch
	$8
	<-
	$1f
	btn
	switch
	or
;

: main
begin 
	read16
	read16
	add
	7seg
again
;

start 
	main
endprogram
