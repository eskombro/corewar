.name "Meow Luigi"
.comment "Here we meoooooow !"
	zjmp				%0
	ld					%0, r16
	sti					r1, %:label_1, %1
	fork				%:label_4

label_1:
	live				%0
	fork				%:label_5
	zjmp				%65528

label_2:
	live				%0
	st					r15, -200
	st					r15, -201
	st					r15, -202
	st					r15, -203
	st					r15, -204
	st					r15, -205
	st					r15, -206
	st					r15, -207

label_3:
	live				%0
	st					r15, -213
	st					r15, -214
	st					r15, -215
	st					r15, -216
	st					r15, -217
	zjmp				%65461

label_4:
	live				%0
	fork				%65453
	zjmp				%65528
	live				%0
	fork				%65520
	zjmp				%65517

label_5:
	sti					r1, %:label_11, %1
	sti					r1, %:label_1, %1
	sti					r1, %:label_7, %1
	sti					r1, %:label_8, %1
	sti					r1, %:label_9, %1
	sti					r1, %:label_10, %1
	sti					r1, %:label_4, %1
	sti					r1, %:label_4, %1
	sti					r1, %:label_2, %1
	sti					r1, %:label_3, %1
	sti					r1, %:label_10, %1
	sti					r1, %:label_10, %6
	sti					r1, %:label_10, %11
	sti					r1, %:label_10, %16
	sti					r1, %:label_10, %:label_6
	sti					r1, %:label_10, %26
	sti					r1, %:label_10, %31

label_6:
	sti					r1, %:label_10, %36
	sti					r1, %:label_10, %41
	sti					r1, %:label_10, %46
	sti					r1, %:label_10, %51
	sti					r1, %:label_10, %56
	sti					r1, %:label_10, %:label_10
	sti					r1, %:label_10, %66
	sti					r1, %:label_10, %71
	sti					r1, %:label_10, %76
	fork				%65332

label_7:
	live				%0
	fork				%:label_11

label_8:
	live				%0
	fork				%:label_9
	zjmp				%65528

label_9:
	live				%0
	fork				%:label_10
	zjmp				%65528

label_10:
	live				%42
	live				%42
	live				%42
	live				%42
	live				%42
	live				%42
	live				%42
	live				%42
	live				%42
	live				%42
	live				%42
	live				%42
	live				%:label_12
	live				%42
	live				%42
	live				%42
	zjmp				%65456

label_11:
	live				%0
	ld					%0, r4
	ld					%8, r5

label_12:
	ld					%4, r6
	ld					%220, r8
	fork				%65420
	ld					%4, r4
	live				%0
	ldi					%:label_7, r4, r2
	sti					r2, %:label_13, r4
	add					r4, r5, r4
	sub					r4, r8, r16
	zjmp				%:label_13
	sub					r16, r6, r16
	zjmp				%:label_13
	ld					%0, r16
	zjmp				%65365

label_13:
	live				%0
