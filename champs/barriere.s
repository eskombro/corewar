.name "Barriere"
.comment "Envoie des torpilles a l'avant et se protege avec des barrieres a l'avant et a l'arriere"
	and					r6, %0, r6
	zjmp				%:label_3

label_1:
	ld					%-5, r5
	ld					%1024, r4
	ld					%-5, r3

label_2:
	live				%42
	sti					r4, %:label_1, r3
	add					r3, r5, r3
	sti					r4, %:label_1, r3
	add					r3, r5, r3
	sti					r4, %:label_1, r3
	add					r3, r5, r3
	sti					r4, %:label_1, r3
	add					r3, r5, r3
	sti					r4, %:label_1, r3
	add					r3, r5, r3
	xor					r3, %-430, r15
	zjmp				%65461
	and					r6, %0, r6
	zjmp				%65457
	live				%42
	fork				%65428
	zjmp				%65425
	live				%42
	sti					r1, %:label_6, r9
	sti					r1, %:label_7, r9
	sti					r1, %:label_8, r9
	sti					r1, %:label_9, r9
	sti					r1, %:label_10, r9
	sti					r1, %:label_11, r9
	sti					r1, %:label_12, r9
	sti					r1, %:label_13, r9
	sti					r1, %:label_14, r9
	sti					r1, %:label_15, r9
	sti					r1, %:label_16, r9
	sti					r1, %:label_17, r9
	sti					r1, %:label_18, r9
	sti					r1, %:label_19, r9
	sti					r1, %:label_20, r9
	sti					r1, %:label_21, r9
	sti					r1, %:label_22, r9
	sti					r1, %:label_23, r9
	sti					r1, %:label_24, r9
	sti					r1, %:label_25, r9
	sti					r1, %:label_26, r9
	sti					r1, %:label_27, r9
	sti					r1, %:label_28, r9
	sti					r1, %:label_29, r9
	sti					r1, %:label_30, r9
	xor					r9, %6, r10
	zjmp				%:label_5
	ld					%6, r9
	and					r6, %0, r6
	zjmp				%65355

label_3:
	fork				%:label_35
	live				%:label_4
	sti					r1, %:label_2, %1
	fork				%65223
	live				%42
	sti					r1, %:label_33, %1
	fork				%:label_31
	live				%42
	ld					%1, r9

label_4:
	and					r6, %0, r6
	zjmp				%65299

label_5:
	live				%42
	fork				%:label_6
	live				%42
	fork				%65523
	live				%42
	zjmp				%65515

label_6:
	live				%42
	live				%42

label_7:
	live				%42
	live				%42

label_8:
	live				%42
	live				%42

label_9:
	live				%42
	live				%42

label_10:
	live				%42
	live				%42

label_11:
	live				%42
	live				%42

label_12:
	live				%42
	live				%42

label_13:
	live				%42
	live				%42

label_14:
	live				%42
	live				%42

label_15:
	live				%42
	live				%42

label_16:
	live				%42
	live				%42

label_17:
	live				%42
	live				%42

label_18:
	live				%42
	live				%42

label_19:
	live				%42
	live				%42

label_20:
	live				%42
	live				%42

label_21:
	live				%42
	live				%42

label_22:
	live				%42
	live				%42

label_23:
	live				%42
	live				%42

label_24:
	live				%42
	live				%42

label_25:
	live				%42
	live				%42

label_26:
	live				%42
	live				%42

label_27:
	live				%42
	live				%42

label_28:
	live				%42
	live				%42

label_29:
	live				%42
	live				%42

label_30:
	live				%42
	live				%42
	zjmp				%65291

label_31:
	live				%42
	fork				%:label_32
	zjmp				%65528

label_32:
	ld					%-5, r5
	ld					%12, r4
	ld					%10, r3

label_33:
	live				%1
	sti					r4, %:label_34, r3
	sub					r3, r5, r3
	sti					r4, %:label_34, r3
	sub					r3, r5, r3
	sti					r4, %:label_34, r3
	sub					r3, r5, r3
	sti					r4, %:label_34, r3
	sub					r3, r5, r3
	sti					r4, %:label_34, r3
	sub					r3, r5, r3
	xor					r3, %435, r15
	zjmp				%65461
	and					r6, %0, r6
	zjmp				%65457

label_34:
	zjmp				%65454

label_35:
	live				%42
	fork				%:label_36
	live				%42
	fork				%:label_37
	live				%42
	fork				%:label_39
	ld					%12, r2
	ld					%192, r5
	and					r6, %0, r6
	zjmp				%:label_42

label_36:
	live				%42
	fork				%:label_38
	live				%42
	fork				%:label_41
	ld					%0, r2
	ld					%180, r5
	and					r6, %0, r6
	zjmp				%:label_42

label_37:
	live				%42
	fork				%:label_40
	live				%42
	ld					%8, r2
	ld					%188, r5
	and					r6, %0, r6
	zjmp				%:label_42

label_38:
	live				%42
	fork				%65033
	ld					%4, r2
	ld					%184, r5
	and					r6, %0, r6
	zjmp				%:label_42

label_39:
	ld					%16, r2
	ld					%196, r5
	and					r6, %0, r6
	zjmp				%:label_42

label_40:
	ld					%20, r2
	ld					%200, r5
	and					r6, %0, r6
	zjmp				%:label_42

label_41:
	ld					%24, r2
	ld					%204, r5
	and					r6, %0, r6
	zjmp				%:label_42

label_42:
	ldi					%0, r2, r3
	sti					r3, r5, %:label_34
	live				%42
	and					r6, %0, r6
	zjmp				%180
