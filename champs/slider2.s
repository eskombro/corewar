.name "Sliders"
.comment "And the winner is ..."
	sti					r1, %:label_7, %1
	sti					r1, %:label_3, %1
	sti					r1, %:label_4, %1
	sti					r1, %:label_10, %1
	sti					r1, %:label_11, %1
	sti					r1, %:label_12, %1
	sti					r1, %:label_5, %1
	sti					r1, %:label_13, %1
	sti					r1, %:label_13, %1
	sti					r1, %:label_13, %6
	sti					r1, %:label_13, %11
	sti					r1, %:label_13, %16
	sti					r1, %:label_13, %:label_1
	sti					r1, %:label_13, %26
	sti					r1, %:label_13, %31

label_1:
	sti					r1, %:label_13, %36
	sti					r1, %:label_13, %41
	sti					r1, %:label_13, %46
	sti					r1, %:label_13, %51
	sti					r1, %:label_13, %:label_2
	sti					r1, %:label_13, %61
	sti					r1, %:label_13, %66
	sti					r1, %:label_13, %71
	sti					r1, %:label_13, %76
	sti					r1, %:label_13, %81
	sti					r1, %:label_13, %86
	sti					r1, %:label_13, %91

label_2:
	sti					r1, %:label_13, %96
	sti					r1, %:label_13, %101
	sti					r1, %:label_13, %106
	sti					r1, %:label_13, %111
	sti					r1, %:label_13, %116
	ld					%48, r14
	ld					%4, r4
	ld					%48, r6
	ld					%48, r13
	ld					%:label_8, r8
	ld					%330, r9
	add					r8, r9, r8
	ld					%:label_9, r12
	sub					r12, r8, r12

label_3:
	live				%42
	fork				%:label_13

label_4:
	live				%42
	fork				%:label_6

label_5:
	live				%42
	fork				%:label_9
	ld					%0, r15
	zjmp				%:label_11

label_6:
	ld					%0, r2

label_7:
	live				%42
	ldi					%:label_6, r2, r3
	sti					r3, r8, r2
	add					r2, r4, r2
	xor					r13, r2, r7
	zjmp				%415
	ld					%0, r15

label_8:
	zjmp				%65500

label_9:
	ld					%0, r10

label_10:
	live				%42
	ldi					%:label_9, r10, r11
	sti					r11, r12, r10
	add					r10, r4, r10
	xor					r6, r10, r7
	zjmp				%65175
	ld					%0, r15
	zjmp				%65500

label_11:
	live				%42
	fork				%65439

label_12:
	live				%42
	fork				%65477
	ld					%0, r15
	zjmp				%65513

label_13:
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
	zjmp				%65416
	live				%42
	fork				%65408
	ld					%0, r15
	zjmp				%65398
