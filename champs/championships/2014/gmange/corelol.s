.name "laugh"
.comment "aff, just kidding"
	sti					r1, %:label_1, %1
	fork				%:label_1
	add					r2, r3, r4

label_1:
	live				%0
	zjmp				%65531
