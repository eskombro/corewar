.name "L'arene des abeilles"
.comment "Baby, baby, baby, oh !"
	sti					r1, %:label_5, %1
	sti					r1, %:label_4, %1
	sti					r1, %:label_6, %1
	sti					r1, %:label_1, %1
	sti					r1, %:label_7, %1
	sti					r1, %:label_2, %1
	sti					r1, %:label_3, %1
	sti					r1, %:label_8, %1
	sti					r1, %:label_9, %1
	ld					%0, r16
	fork				%:label_5

label_1:
	live				%314
	ld					%31415926, r2
	ld					%0, r16
	fork				%:label_6

label_2:
	live				%314
	ld					%0, r16
	fork				%:label_7

label_3:
	ld					%62821932, r5
	ld					%0, r16
	fork				%:label_8

label_4:
	live				%314
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	st					r2, -450
	zjmp				%65456

label_5:
	live				%314
	zjmp				%65531

label_6:
	live				%314
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	st					r2, 450
	zjmp				%65456

label_7:
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	live				%314
	zjmp				%65230

label_8:
	zjmp				%:label_9
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500

label_9:
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
	st					r5, 500
