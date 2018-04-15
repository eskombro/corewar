.name "Varimathras"
.comment "If I have wings, why am I always walking?"

label_1:
	st					r1, r9
	live				%0
	ld					%656, r1
	ld					%151162880, r2
	sti					r1, %:label_1, %0
	sti					r9, %:label_1, %4
	sti					r2, %:label_1, %8
	ld					%0, r1
	ld					%4, r3
	ld					%88, r4
	sti					r9, %:label_2, %1
	sti					r9, %:label_3, %1
	sti					r9, %:label_4, %1
	sti					r9, %:label_5, %1

label_2:
	live				%0
	ldi					%:label_2, r1, r2

label_3:
	live				%0
	sti					r2, %209, r1

label_4:
	live				%0
	add					r1, r3, r1
	xor					r1, r4, r16
	zjmp				%:label_6

label_5:
	live				%0
	and					%0, %0, r16
	zjmp				%65480

label_6:
	ld					%0, r1
	and					%0, %0, r16
	zjmp				%148
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
