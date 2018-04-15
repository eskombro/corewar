.name "dtonc v1.0pl4"
.comment "ta mere elle fait du rodeo sur les kfar"

label_1:
	st					r1, 32
	st					r1, 54
	ld					%100, r4
	ld					%4, r6
	ld					%0, r3
	live				%1
	ldi					%:label_1, r3, r2
	sti					r2, %400, r3
	add					r3, r6, r3
	sub					r3, r4, r5
	live				%1
	zjmp				%337
	ld					%0, r5
	zjmp				%65499
