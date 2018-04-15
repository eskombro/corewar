.name "turtle"
.comment "TURTLE FFS U LAMA"
	sti					r1, %:label_4, %1
	sti					r1, %:label_2, %1
	sti					r1, %:label_5, %1
	sti					r1, %:label_1, %1
	ld					%0, r16
	fork				%:label_4

label_1:
	live				%:label_3
	ld					%439025904, r2
	ld					%0, r16
	fork				%:label_5

label_2:
	live				%42
	st					r2, -400
	st					r2, -400
	st					r2, -400

label_3:
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	st					r2, -400
	zjmp				%65376

label_4:
	live				%42
	zjmp				%65531

label_5:
	live				%42
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	st					r2, 400
	zjmp				%65376
