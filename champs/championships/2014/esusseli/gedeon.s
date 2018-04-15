.name "Gédéon le Cochon"
.comment "Tout est bon dans Gédéon"
	sti					r1, %:label_3, %1
	sti					r1, %:label_4, %1

label_1:
	sti					r1, %:label_4, %9
	sti					r1, %:label_4, %17
	sti					r1, %:label_4, %25
	sti					r1, %:label_5, %1

label_2:
	sti					r1, %:label_6, %1
	sti					r1, %:label_7, %1
	ld					%0, r1
	fork				%:label_4
	ld					%0, r1

label_3:
	live				%1337
	st					r1, -16
	st					r1, -25
	st					r1, -34
	st					r1, -43
	st					r1, -52
	st					r1, :label_2
	st					r1, -70
	st					r1, -79
	st					r1, -88
	st					r1, -97
	st					r1, -106
	st					r1, -115
	st					r1, :label_1
	st					r1, -133
	st					r1, -142
	st					r1, -151
	st					r1, -160
	st					r1, -410
	st					r1, -411
	st					r1, -412
	st					r1, -413
	st					r1, -414
	st					r1, -425
	st					r1, -416
	st					r1, -417
	st					r1, -418
	st					r1, -419
	ld					%0, r1
	zjmp				%65389

label_4:
	live				%1337
	fork				%65381
	live				%1337
	fork				%:label_7
	live				%1337
	fork				%:label_5
	live				%1337
	fork				%65507
	zjmp				%65504

label_5:
	live				%1337
	fork				%65531
	ld					%0, r1

label_6:
	live				%1337
	zjmp				%65531

label_7:
	live				%1337
	st					r1, 30
	st					r1, 29
	st					r1, 28
	st					r1, 27
	ld					%0, r1
	zjmp				%65504
