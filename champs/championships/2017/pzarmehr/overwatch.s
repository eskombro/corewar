.name "Overwatch"
.comment "Reinhardt, Pharah, Mercy, Mei, Symmetra & Torbjorn"
	ld					%1, r16
	st					r1, 6

label_1:
	live				%0
	zjmp				%65531
	st					r15, -12
	st					r16, -22
	fork				%:label_3
	st					r1, 6
	live				%0
	fork				%:label_5
	st					r1, 6
	live				%0
	ld					%589824, r13
	ld					%8, r14
	ld					%-511, r15
	ld					%0, r16
	zjmp				%:label_2

label_2:
	ld					%190057742, r11
	ld					%269090402, r12
	ld					%0, r16
	st					r11, -501
	st					r12, -502
	zjmp				%65025

label_3:
	st					r1, 6
	live				%0
	fork				%:label_4
	st					r1, 6
	live				%0
	ld					%190057743, r13
	ld					%-409, r14
	ld					%-21, r15
	ld					%0, r16
	zjmp				%65451

label_4:
	st					r1, 6
	live				%0
	ld					%269090790, r13
	ld					%-405, r14
	ld					%-17, r15
	ld					%0, r16
	zjmp				%65410
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0
	fork				%0

label_5:
	ldi					%:label_1, %0, r1
	ldi					%:label_1, %4, r2
	ld					%196608, r3
	add					r2, r3, r3
	ld					%57671937, r16
	st					r16, 511
	ld					%-16551933, r16
	st					r16, 503
	ld					%33424240, r16
	st					r16, 495
	ld					%16907523, r16
	st					r16, 487
	ld					%1879245308, r16
	st					r16, 479
	ld					%57671937, r16
	st					r16, 471
	ld					%-83660798, r16
	st					r16, 463
	ld					%33162096, r16
	st					r16, 455
	ld					%285205251, r16
	st					r16, 447
	ld					%1880162275, r16
	st					r16, 439
	ld					%57676031, r16
	st					r16, 431
	ld					%-486313968, r16
	st					r16, 423
	ld					%-1899664, r16
	st					r16, 415
	ld					%285205251, r16
	st					r16, 407
	ld					%1880162275, r16
	st					r16, 399
	ld					%151110400, r16
	st					r16, 391
	ld					%0, r16
	zjmp				%319