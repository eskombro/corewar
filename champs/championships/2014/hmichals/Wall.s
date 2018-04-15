.name "Wall"
.comment "Werror(you) Wextra(me)"

label_1:
	ld					%1, r14
	zjmp				%65529
	st					r15, -8
	sti					r1, %:label_1, %1
	sti					r1, %:label_5, %1
	sti					r1, %:label_4, %1
	sti					r1, %:label_1, %1
	sti					r1, %:label_2, %1
	sti					r1, %:label_2, %9
	sti					r1, %:label_3, %1
	sti					r1, %:label_3, %9
	sti					r1, %:label_3, %17

label_2:
	live				%:label_6
	fork				%65453
	live				%66
	fork				%65523

label_3:
	live				%-1717986919
	fork				%925
	live				%66
	fork				%1941
	live				%66
	fork				%2957

label_4:
	live				%66
	fork				%65531
	aff					r1

label_5:
	live				%66
	ld					%0, r16
	zjmp				%65524

label_6:
	live				%66
	ld					%42991616, r2
	ld					%265, r3
	ld					%-458752, r4
	fork				%65366
	live				%66
	st					r2, -300
	st					r3, -301
	st					r4, -302
	st					r2, -303
	st					r3, -304
	st					r4, -305
	st					r2, -306
	st					r3, -307
	st					r4, -308
	st					r2, -309
	st					r3, -310
	st					r4, -311
	st					r2, -312
	st					r3, -313
	st					r4, -314
	st					r2, -315
	st					r3, -316
	st					r4, -317
	st					r2, -318
	st					r3, -319
	st					r4, -320
	st					r2, -321
	st					r3, -322
	st					r4, -323
	st					r2, -324
	st					r3, -325
	st					r4, -326
	st					r2, -327
	st					r3, -328
	st					r4, -329
	ld					%0, r16
	zjmp				%65201
