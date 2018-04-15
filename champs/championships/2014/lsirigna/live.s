.name "zdoh"
.comment "w8 for da next one"
	sti					r3, -1, %1
	and					r3, %0, r3
	fork				%:label_1
	ld					0, r4
	st					r4, -6
	zjmp				%65523

label_1:
	live				%0
	live				%42
	fork				%:label_9

label_2:
	fork				%:label_9
	fork				%:label_9
	fork				%:label_9
	fork				%:label_9
	fork				%:label_9

label_3:
	fork				%:label_9
	fork				%:label_9
	fork				%:label_9
	fork				%:label_9
	fork				%65496

label_4:
	fork				%65493
	fork				%:label_9
	fork				%65487
	fork				%:label_8
	fork				%:label_9

label_5:
	fork				%:label_10
	fork				%:label_10
	fork				%:label_10
	fork				%:label_10
	fork				%:label_10

label_6:
	fork				%:label_10
	fork				%:label_10
	fork				%:label_10
	fork				%:label_10
	fork				%:label_10

label_7:
	fork				%:label_10
	fork				%:label_10

label_8:
	fork				%65442

label_9:
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	live				%1
	fork				%:label_10
	fork				%65453

label_10:
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
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -500
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, -400
	st					r8, :label_2
	st					r8, -400
	st					r8, -400
	st					r8, :label_3
	st					r8, -400
	st					r8, -400
	st					r8, :label_4
	st					r8, -400
	st					r8, -400
	st					r8, :label_5
	st					r8, -400
	st					r8, -400
	st					r8, :label_6
	st					r8, -400
	st					r8, -400
	st					r8, :label_7
	st					r8, -400
	zjmp				%65221
