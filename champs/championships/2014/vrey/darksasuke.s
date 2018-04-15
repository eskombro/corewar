.name "Xx_DaRk_SaSuKe_93_xX"
.comment "The Dirty Hamster"
	st					r1, 235
	st					r1, 205
	ld					%8, r15
	ld					%1, r16
	ld					%-400, r13
	ld					%0, r11
	ld					%0, r16
	zjmp				%:label_3

label_1:
	live				%9999999

label_2:
	fork				%65531

label_3:
	ld					:label_2, r9
	ld					:label_1, r7
	ld					-17, r8
	ld					%300, r10
	fork				%:label_6
	live				%999999
	fork				%:label_5
	ld					%0, r16
	zjmp				%:label_4

label_4:
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
	live				%93999
	live				%93999
	live				%93999
	live				%93999
	live				%93999
	live				%93999
	live				%93999
	live				%93999
	live				%93999
	live				%93999
	zjmp				%65486

label_5:
	live				%9999999
	sub					r13, r15, r13
	sti					r9, r10, r13
	ld					%0, r16
	zjmp				%65514

label_6:
	live				%9999999
	add					r11, r15, r11
	sti					r7, r10, r11
	sti					r8, r10, r11
	ld					%0, r16
	zjmp				%65509
