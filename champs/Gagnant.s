.name "Celebration Funebre v0.99pl42"
.comment "Jour J"
	ld					%0, r3

label_1:
	zjmp				%:label_7
	zjmp				%0

label_2:
	live				%:label_4
	sti					r15, %0, r14
	zjmp				%65336

label_3:
	live				%:label_6
	sti					r15, %0, r14
	zjmp				%65336
	live				%42
	sti					r15, %0, r14
	zjmp				%65336

label_4:
	live				%42

label_5:
	sti					r15, %0, r14
	zjmp				%65336

label_6:
	sti					r15, %0, r14
	zjmp				%65336
	sti					r15, %0, r14
	zjmp				%65336

label_7:
	sti					r1, %:label_2, %1
	sti					r1, %:label_2, %15
	sti					r1, %:label_2, %29
	sti					r1, %:label_2, %43
	sti					r1, %:label_2, %57
	sti					r1, %:label_2, %:label_8
	ld					%393216, r4
	ld					%917504, r12
	ld					%1, r11
	ld					%6, r10
	live				%42
	sti					r4, %:label_1, %1
	add					r4, r12, r4
	sub					r10, r11, r10
	zjmp				%65486
	fork				%65511
	live				%3
	fork				%:label_9

label_8:
	live				%4
	fork				%:label_11
	live				%:label_10
	ldi					%8, %:label_2, r15
	ld					%:label_3, r14
	ld					%0, r2
	zjmp				%65316

label_9:
	live				%:label_12
	fork				%:label_13
	live				%42

label_10:
	ldi					%4, %:label_2, r15
	ld					%:label_5, r14
	ld					%0, r2
	zjmp				%65279

label_11:
	live				%42

label_12:
	ldi					%12, %:label_2, r15
	ld					%-182, r14
	ld					%0, r2
	zjmp				%65250

label_13:
	live				%42
	ldi					%0, %:label_2, r15
	ld					%-194, r14
	ld					%0, r2
	zjmp				%65221
