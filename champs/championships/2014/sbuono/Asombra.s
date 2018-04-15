.name "King Sombra"
.comment "Crystal empire is mine!"
	fork				%:label_2
	live				%0
	fork				%:label_3
	ld					%251658255, r2
	ld					%1, r12
	ld					%40, r11
	st					r1, 11
	st					r16, -4

label_1:
	live				%0
	st					r16, -300
	st					r2, -301
	st					r2, -302
	sub					r11, r12, r11
	zjmp				%:label_4
	ld					%0, r16
	zjmp				%65501

label_2:
	ld					%0, r16
	zjmp				%:label_11

label_3:
	ld					%0, r16
	zjmp				%:label_10

label_4:
	ldi					%:label_1, %1, r13
	ld					%0, r16
	st					r13, 6
	live				%0
	fork				%65531
	st					r13, 6
	live				%0
	fork				%:label_5
	ld					%190056971, r10
	ld					%135004416, r7
	ld					%:label_8, r8
	ld					%270, r11
	ld					%0, r12
	fork				%:label_6
	zjmp				%:label_9

label_5:
	ld					%202068999, r10
	st					r13, r7
	ld					%276, r8
	ld					%274, r11
	ld					%0, r12
	fork				%:label_6
	zjmp				%:label_9

label_6:
	zjmp				%:label_7

label_7:
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12

label_8:
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0

label_9:
	sti					r10, r11, r12
	sti					r7, r8, r12
	live				%0

label_10:
	live				%0
	ld					%190055943, r10
	ld					%84476405, r11
	ld					%150994956, r3
	ld					%150994956, r6
	ld					%26, r7
	ld					%495, r4
	ld					%0, r5
	zjmp				%:label_13

label_11:
	live				%0
	ld					%190055943, r10
	ld					%84476405, r11
	fork				%:label_12
	ld					%190055172, r3
	ld					%190055172, r6
	ld					%507, r7
	ld					%24, r4
	ld					%0, r5
	zjmp				%:label_13

label_12:
	live				%0
	ld					%84475923, r3
	ld					%84475923, r6
	ld					%511, r7
	ld					%28, r4
	ld					%0, r5
	zjmp				%:label_13

label_13:
	live				%0
	st					r10, 511
	st					r11, 510
	zjmp				%501
