.name "top defense plus plus"
.comment "la meilleure defense c'est d'avoir une bonne defense"

label_1:
	ld					%-16, r5
	ld					%-12, r4
	ld					%-8, r6
	ld					%150994944, r10
	ld					%42991616, r2
	ld					%256, r3
	ld					%16, r16
	ld					%12, r7
	ld					%16, r9
	ld					%20, r11
	ld					%23, r12
	ld					%1, r13
	ld					%0, r8
	sti					r1, %:label_2, %1
	sti					r1, %:label_5, %1
	sti					r1, %:label_3, %1
	sti					r1, %:label_4, %1
	fork				%:label_3

label_2:
	live				%-530930513
	sti					r2, %:label_1, r5
	sti					r3, %:label_1, r4
	sti					r10, %:label_1, r6
	sub					r5, r16, r5
	sub					r4, r16, r4
	sub					r6, r16, r6
	sub					r12, r13, r12
	zjmp				%65371
	ld					%0, r8
	zjmp				%65483

label_3:
	live				%13371337
	fork				%65475
	live				%42424242
	fork				%:label_5
	live				%123456789
	fork				%65515
	live				%-194501935
	fork				%:label_4
	zjmp				%65504

label_4:
	live				%1663336123
	zjmp				%65496

label_5:
	live				%1713792036
	sti					r2, %51, r7
	sti					r3, %45, r9
	sti					r10, %39, r11
	add					r7, r16, r7
	add					r9, r16, r9
	add					r11, r16, r11
	sub					r12, r13, r12
	zjmp				%65272
	ld					%0, r8
	zjmp				%65483
