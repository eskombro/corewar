.name "Tching tching(Intercepteur), Bouh!Bouh!(bruits d'anti-jeu)"
.comment ""
	fork				%:label_4
	ld					%-272, r3
	live				%0
	fork				%:label_2
	ld					%-272, r3
	fork				%:label_1
	ld					%0, r2
	ld					%0, r4
	zjmp				%:label_8

label_1:
	ld					%4, r2
	ld					%0, r4
	zjmp				%:label_8

label_2:
	ld					%-202, r3
	fork				%:label_3
	ld					%0, r2
	ld					%0, r4
	zjmp				%:label_12

label_3:
	ld					%4, r2
	ld					%0, r4
	zjmp				%:label_12

label_4:
	ld					%400, r3
	live				%0
	fork				%:label_6
	fork				%:label_5
	ld					%0, r2
	ld					%0, r4
	zjmp				%:label_10

label_5:
	ld					%4, r2
	ld					%0, r4
	zjmp				%:label_10

label_6:
	fork				%:label_7
	ld					%0, r4
	zjmp				%:label_14

label_7:
	ld					%0, r4
	zjmp				%:label_15

label_8:
	ldi					r2, %:label_9, r6
	ld					%0, r4
	live				%1

label_9:
	sti					r6, r2, r3
	zjmp				%65259

label_10:
	ldi					r2, %:label_11, r6
	ld					%0, r4
	live				%1

label_11:
	sti					r6, r2, r3
	zjmp				%395

label_12:
	ldi					r2, %:label_13, r6
	ld					%0, r4
	live				%1

label_13:
	sti					r6, r2, r3
	zjmp				%65329

label_14:
	live				%1
	fork				%65531
	zjmp				%65528

label_15:
	live				%1
	fork				%65531
	zjmp				%65528
