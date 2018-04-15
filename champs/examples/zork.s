.name "zork"
.comment "I'M ALIIIIVE"
	sti					r1, %:label_1, %1
	and					r1, %0, r1

label_1:
	live				%1
	zjmp				%65531
