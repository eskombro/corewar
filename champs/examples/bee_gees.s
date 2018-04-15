.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	sti					r1, %:label_1, %1
	sti					r1, %:label_1, %1
	ld					%1, r3
	ld					%33, r6
	add					r2, r3, r2
	xor					r2, %15, r4

label_1:
	live				%4
	zjmp				%:label_2
	fork				%65515
	ld					%0, r4
	zjmp				%65505

label_2:
	ld					%0, r4
	live				%4
	zjmp				%65503
