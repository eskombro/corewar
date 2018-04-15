.name " maxidef "
.comment " module de defense"

label_1:
	live				%0
	zjmp				%:label_2
	st					r1, 6

label_2:
	live				%66
	ld					-4, r1
	st					r2, -14
	ld					%0, r5
	zjmp				%:label_5
	zjmp				%65044

label_3:
	live				%1
	st					r2, -385
	st					r4, -386
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510
	st					r3, -510

label_4:
	live				%1
	zjmp				%65416

label_5:
	ld					%57672703, r3
	sti					r1, %:label_1, %1
	sti					r1, %:label_6, %1
	sti					r1, %:label_6, %9
	sti					r1, %:label_7, %1
	sti					r1, %:label_8, %1
	sti					r1, %:label_9, %1
	sti					r1, %:label_4, %1
	sti					r1, %:label_3, %1
	ld					:label_4, r2
	ldi					%:label_4, %4, r4
	ld					%0, r5

label_6:
	live				%1
	fork				%65531
	live				%1
	zjmp				%:label_7

label_7:
	live				%1
	fork				%:label_9

label_8:
	live				%1
	zjmp				%65287

label_9:
	live				%1
	zjmp				%65276
