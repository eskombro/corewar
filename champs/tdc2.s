.name "dtonc v1.0pl2"
.comment "ta mere elle fait du rodeo sur les kfar"

label_1:
	ld					%15, r3
	ld					%195, r4
	ld					%0, r7
	ld					%589824, r8
	live				%1
	fork				%65531
	ld					%0, r5
	fork				%:label_2
	live				%1
	fork				%:label_3
	live				%1
	fork				%:label_3
	zjmp				%65502

label_2:
	live				%1
	zjmp				%65531

label_3:
	live				%1
	fork				%65531
	live				%1
	sti					r8, %:label_5, r2
	add					r2, r3, r2
	sub					r4, r2, r5
	zjmp				%:label_4
	ld					%0, r5
	zjmp				%65505

label_4:
	ld					%0, r2
	zjmp				%65495
	live				%1
	fork				%65479
	live				%1
	sti					r7, %:label_1, r2
	sub					r2, r3, r2
	add					r4, r2, r5
	zjmp				%65497
	ld					%0, r5
	zjmp				%65453
	ld					%0, r2
	zjmp				%65443
	live				%0
	xor					r1, r1, r5
	zjmp				%65526

label_5:
	xor					r1, r1, r1
