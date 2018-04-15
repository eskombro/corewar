.name "Jumper !"
.comment "en fait C forker !"
	st					r1, :label_4
	st					r6, -4
	ld					:label_4, r1

label_1:
	ld					%0, r7
	zjmp				%:label_5

label_2:
	live				%66
	ldi					%:label_2, r3, r1
	sti					r1, %-173, r3
	add					r3, r4, r3
	xor					r5, r3, r6
	zjmp				%:label_3
	ld					%0, r7
	zjmp				%65499

label_3:
	xor					r3, r3, r3
	zjmp				%65329

label_4:
	st					r1, r1

label_5:
	sti					r1, %:label_6, %1

label_6:
	live				%:label_7
	sti					r2, %:label_1, %-60
	ld					%4, r4
	st					r2, 512
	ld					%48, r5
	sti					r1, %:label_2, %1
	sti					r1, %:label_16, %1
	sti					r1, %:label_8, %1
	sti					r1, %:label_9, %1
	sti					r1, %:label_10, %1

label_7:
	sti					r1, %:label_11, %1
	sti					r1, %:label_12, %1

label_8:
	live				%66

label_9:
	live				%66

label_10:
	live				%:label_14

label_11:
	live				%:label_15

label_12:
	live				%66
	zjmp				%65511
	xor					r3, r3, r3
	sti					r1, %:label_13, %1

label_13:
	live				%66
	fork				%65491
	sti					r1, %:label_14, %1
	sti					r1, %:label_14, %9
	sti					r1, %:label_14, %17
	sti					r1, %:label_14, %25

label_14:
	live				%66

label_15:
	fork				%65316
	live				%66
	fork				%65523
	live				%66
	fork				%:label_16
	live				%66
	zjmp				%65292

label_16:
	live				%66
	ldi					%:label_16, r3, r1
	sti					r1, %17, r3
	add					r3, r4, r3
	xor					r5, r3, r6
	zjmp				%:label_17
	ld					%0, r7
	zjmp				%65499

label_17:
	xor					r3, r3, r3
	zjmp				%1
