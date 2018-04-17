.name "NotMyProblem"
.comment "I dont care about you..."

label_1:
	or					r3, %-16186880, r3
	sti					r3, %0, %:label_1
	sti					r3, %3, %:label_1
	sti					r3, %6, %:label_1
	sti					r3, %9, %:label_1
	sti					r3, %12, %:label_1
	sti					r3, %15, %:label_1
	sti					r3, %18, %:label_1
	fork				%:label_3
	fork				%:label_4
	sti					r1, %0, %8
	live				%0
	and					r2, %0, r2
	zjmp				%65516

label_2:
	sti					r1, %0, %8
	live				%0
	xor					r2, %1, r2
	or					r2, %0, r2
	zjmp				%65508
	and					r2, %0, r2
	zjmp				%65468

label_3:
	sti					r1, %:label_2, %8
	live				%0
	and					r2, %0, r2
	zjmp				%65474

label_4:
	sti					r1, %:label_2, %8
	live				%0
	and					r2, %0, r2
	zjmp				%65422
