.name "🎂"
.comment "🎂"

label_1:
	ld					%0, r10
	zjmp				%:label_5
	live				%2
	ld					%251658240, r2
	ld					%0, r10
	fork				%:label_2
	st					r2, -511
	st					r2, -505
	st					r2, -499
	st					r2, -493
	st					r2, -487
	st					r2, -481
	st					r2, -475
	st					r2, -469
	zjmp				%65496

label_2:
	live				%2
	st					r2, -471
	st					r2, -465
	st					r2, -459
	st					r2, -453
	st					r2, -447
	st					r2, -441
	st					r2, -435
	zjmp				%65501
	ld					%71, r1
	aff					r1
	ld					%82, r1
	aff					r1
	ld					%79, r1
	aff					r1
	ld					%83, r1
	aff					r1
	ld					%32, r1
	aff					r1
	ld					%83, r1
	aff					r1
	ld					%65, r1
	aff					r1
	ld					%:label_3, r1
	aff					r1
	ld					%32, r1
	aff					r1
	ld					%71, r1
	aff					r1
	ld					%82, r1
	aff					r1
	ld					%:label_4, r1
	aff					r1
	ld					%83, r1
	aff					r1
	ld					%32, r1

label_3:
	aff					r1
	ld					%83, r1
	aff					r1
	ld					%65, r1
	aff					r1
	ld					%67, r1
	aff					r1
	ld					%32, r1
	aff					r1
	fork				%0
	fork				%0
	fork				%0

label_4:
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
	live				%2

label_5:
	st					r1, :label_1
	st					r16, :label_5

label_6:
	st					r1, 143
	st					r16, :label_6
	fork				%65163
	live				%2
	fork				%:label_13
	live				%2
	fork				%65531
	live				%2
	fork				%:label_7
	or					r2, %:label_9, r2

label_7:
	live				%2
	fork				%:label_8
	or					r2, %:label_9, r2

label_8:
	live				%2
	fork				%:label_10

label_9:
	or					r2, %:label_10, r2

label_10:
	live				%2
	fork				%:label_11
	or					r2, %4, r2

label_11:
	ldi					%:label_12, r2, r16
	ld					%0, r15

label_12:
	sti					r16, %64, r2
	sti					r16, %:label_14, r2
	sti					r16, %:label_16, r2
	sti					r16, %238, r2
	sti					r16, %296, r2
	sti					r16, %354, r2
	live				%2
	live				%2
	sti					r16, %402, r2
	sti					r16, %448, r2
	zjmp				%442
	live				%2

label_13:
	live				%2
	ld					%507, r6
	ld					%8, r8
	ld					%139, r10
	fork				%:label_15
	live				%2
	ld					%4, r2
	ld					%101253622, r3
	ld					%101253622, r5
	ld					%168362119, r7

label_14:
	ld					%262144, r9
	ld					%0, r16
	zjmp				%:label_17

label_15:
	live				%2
	ld					%0, r2
	ld					%190055682, r3
	ld					%190056194, r5
	ld					%190056706, r7
	ld					%134443017, r9
	ld					%0, r16

label_16:
	zjmp				%:label_17

label_17:
	sti					r3, r2, r6
	zjmp				%502
