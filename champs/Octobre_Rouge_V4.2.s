.name "Octobre Rouge V4.2"
.comment "And the winner is ..."
	st					r1, 19
	ld					%0, r15
	fork				%:label_1
	zjmp				%:label_5

label_1:
	live				%42
	fork				%:label_5
	zjmp				%65528
	live				%42
	fork				%:label_2
	st					r1, 13
	ld					%0, r15
	live				%42
	zjmp				%65531

label_2:
	live				%42
	fork				%:label_3
	st					r1, 13
	ld					%0, r15
	live				%42
	zjmp				%65531

label_3:
	live				%42
	fork				%:label_4
	st					r1, 13
	ld					%0, r15
	live				%42
	zjmp				%65531

label_4:
	live				%42
	fork				%65447
	st					r1, 13
	ld					%0, r15
	live				%42
	zjmp				%65531
	live				%42
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	ld					%0, r15
	zjmp				%65269

label_5:
	live				%42
	fork				%:label_6
	live				%42
	fork				%:label_7
	live				%42
	fork				%:label_8
	ld					%57672448, r3
	ld					%318992390, r6
	ld					%0, r15
	zjmp				%:label_9

label_6:
	live				%42
	fork				%65483
	live				%42
	fork				%65093
	ld					%251883526, r3
	ld					%386101254, r6
	ld					%0, r15
	ld					%0, r15
	zjmp				%:label_9

label_7:
	live				%42
	fork				%65166
	ld					%-65214, r3
	ld					%436432902, r6
	ld					%0, r15
	ld					%0, r15
	ld					%0, r15
	zjmp				%:label_9

label_8:
	st					r1, r3
	ld					%251883526, r6
	ld					%0, r15
	ld					%0, r15
	ld					%0, r15
	ld					%0, r15
	zjmp				%:label_9

label_9:
	st					r3, 15
	st					r6, -1
	live				%42
