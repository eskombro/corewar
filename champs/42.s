.name "42"
.comment "Just a basic Winner Program"

label_1:
	live				%42
	ld					%0, r5
	ld					%0, r5
	zjmp				%:label_7
	sti					r1, %:label_3, %1
	ld					%2304, r10
	ld					%1, r5
	ld					%0, r11
	ld					%4, r3
	live				%42
	fork				%:label_2
	live				%:label_28
	sub					r3, r5, r3
	zjmp				%:label_10
	ld					%0, r11
	fork				%:label_6
	live				%42
	sti					r10, %-510, %0
	sti					r10, %-404, %0
	sti					r10, %-303, %0
	sti					r10, %-202, %0
	ld					%0, r11
	zjmp				%65465

label_2:
	ld					%368, r2
	ld					%0, r3
	ld					%4, r4

label_3:
	live				%1
	sti					r10, %-510, r2
	sti					r10, %-510, r3
	add					r4, r5, r4
	add					r3, r4, r3
	sub					r2, r4, r2
	zjmp				%65483
	ld					%0, r11
	zjmp				%65494
	zjmp				%:label_11

label_4:
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	sub					r6, r4, r6
	add					r6, r6, r11
	ldi					%:label_4, r6, r7
	sti					r7, %-510, r11

label_5:
	live				%1
	ld					%0, r10
	sti					r7, %-250, r6
	zjmp				%65344

label_6:
	zjmp				%:label_25

label_7:
	sti					r1, %:label_23, %2
	ldi					%:label_23, %3, r2
	sti					r2, %:label_1, %-4
	ldi					%:label_23, %-1, r2
	sti					r2, %:label_1, %-8
	sti					r1, %:label_5, %1
	sti					r1, %:label_8, %1
	ld					%0, r2
	ld					%8, r3
	ld					%1, r4
	ld					%0, r6

label_8:
	live				%1
	sub					r3, r4, r3
	zjmp				%:label_24
	fork				%:label_9
	st					r5, r2
	xor					r10, r10, r10
	add					r10, r10, r10
	add					r6, r6, r6
	ld					%0, r10
	zjmp				%65494

label_9:
	add					r2, r4, r2
	add					r6, r6, r6
	add					r6, r4, r6
	ld					%0, r10
	zjmp				%65469

label_10:
	live				%42
	ld					%9, r3
	sti					r3, %:label_4, %-6
	ld					%2, r3
	sti					r3, %:label_4, %-16
	ld					%0, r3
	zjmp				%:label_26

label_11:
	sti					r1, %:label_12, %1
	sti					r1, %:label_13, %1
	sti					r1, %:label_14, %1
	sti					r1, %:label_15, %1
	sti					r1, %:label_16, %1
	sti					r1, %:label_17, %1
	sti					r1, %:label_18, %1
	sti					r1, %:label_19, %1
	sti					r1, %:label_20, %1
	sti					r1, %:label_21, %1
	sti					r1, %:label_22, %1

label_12:
	live				%1

label_13:
	live				%1

label_14:
	live				%1

label_15:
	live				%1

label_16:
	live				%1

label_17:
	live				%1

label_18:
	live				%1

label_19:
	live				%1

label_20:
	live				%1

label_21:
	live				%1

label_22:
	live				%1
	zjmp				%65481
	zjmp				%65401
	live				%0

label_23:
	ld					%1, r1

label_24:
	sti					r1, %:label_30, %1
	or					r2, r2, r2
	zjmp				%:label_27
	sub					r2, r4, r2
	zjmp				%65076
	ld					%0, r2
	zjmp				%65356

label_25:
	zjmp				%:label_31

label_26:
	ld					%9, r3
	sti					r3, %:label_34, %-6
	ld					%2, r3
	sti					r3, %:label_34, %-16
	ld					%0, r3
	zjmp				%65315

label_27:
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0

label_28:
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	zjmp				%0
	ld					%10, r8
	sub					r6, r8, r6
	and					r6, %-2147483648, r8
	zjmp				%:label_29
	ld					%:label_32, r8
	add					r6, r8, r6

label_29:
	add					r6, r6, r6
	ld					%272, r8
	ld					%29, r9
	ldi					%:label_27, r6, r7
	sti					r7, r8, r6
	sti					r7, r9, r6

label_30:
	live				%1
	ld					%0, r10
	zjmp				%186

label_31:
	ld					%425, r2
	ld					%0, r3
	ld					%4, r4
	live				%:label_33
	sti					r10, %:label_34, r2
	sti					r10, %:label_34, r3
	add					r4, r5, r4
	add					r3, r4, r3
	sub					r2, r4, r2
	zjmp				%65483

label_32:
	ld					%0, r11

label_33:
	zjmp				%65473
	zjmp				%65176

label_34:
	live				%633
