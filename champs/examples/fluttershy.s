.name "fluttershy"
.comment "oh, my, what a scary project"
	fork				%:label_4
	st					r1, 6
	live				%42
	fork				%:label_8
	st					r1, 6
	live				%42
	fork				%:label_5

label_1:
	st					r1, 6
	live				%213904
	fork				%65526
	sti					r1, %:label_2, %1
	st					r1, 6
	live				%43123
	sti					r1, %:label_3, %1
	ld					%-6, r2
	ld					%-6, r3
	ld					%150994953, r4
	ld					%-186, r5

label_2:
	live				%295423
	sti					r4, %:label_1, r2
	add					r2, r3, r2
	sti					r4, %:label_1, r2
	add					r2, r3, r2

label_3:
	live				%3940641
	xor					r2, r5, r15
	zjmp				%65447
	ld					%0, r16
	zjmp				%65489

label_4:
	st					r1, 6
	live				%123012
	fork				%65526
	st					r1, 58
	st					r1, 58
	st					r1, 58
	st					r1, 58
	st					r1, 58
	st					r1, 58
	st					r1, 58
	st					r1, 58
	st					r1, 58
	st					r1, 58
	ld					%0, r16
	live				%985341
	live				%985341
	live				%985341
	live				%985341
	live				%985341
	live				%985341
	live				%985341
	live				%985341
	live				%985341
	live				%985341
	zjmp				%65486

label_5:
	st					r1, 6
	live				%213904
	fork				%65526
	sti					r1, %:label_6, %1
	st					r1, 6
	live				%43123
	sti					r1, %:label_7, %1
	ld					%0, r2
	ld					%6, r3
	ld					%150994953, r4
	ld					%180, r5

label_6:
	live				%295423
	sti					r4, %153, r2
	add					r2, r3, r2
	sti					r4, %142, r2
	add					r2, r3, r2

label_7:
	live				%3940641
	xor					r2, r5, r15
	zjmp				%65447
	ld					%0, r16
	zjmp				%65489

label_8:
	st					r1, 6
	live				%96824
	fork				%65526

label_9:
	ld					%0, r2
	ld					%4, r3
	ld					%96, r5
	sti					r1, %:label_10, %1
	st					r1, 6
	live				%8008135
	ldi					%:label_9, r2, r4
	sti					r4, %400, r2
	add					r2, r3, r2
	ldi					%:label_9, r2, r4
	sti					r4, %383, r2
	add					r2, r3, r2

label_10:
	live				%89523
	xor					r2, r5, r15
	zjmp				%362
	ld					%0, r15
	zjmp				%65477
