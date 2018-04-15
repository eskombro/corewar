.name "Booster !"
.comment "Alors la, si ca marche, trop content !  :)"
	ld					%12, r2
	ld					%3, r3
	ld					%4, r4
	ld					%5, r7
	sti					r1, %:label_1, %1

label_1:
	live				%66
	sti					r1, %:label_2, %1
	sti					r1, %:label_3, %1
	sti					r1, %:label_4, %1
	sti					r1, %:label_9, %1
	sti					r1, %:label_5, %1
	sti					r1, %:label_6, %1
	sti					r1, %:label_7, %1
	sti					r1, %:label_1, %-4
	ldi					%:label_1, %-2, r6

label_2:
	live				%66
	fork				%:label_6

label_3:
	live				%66
	fork				%:label_7

label_4:
	live				%66

label_5:
	live				%66
	ld					%0, r3
	ld					%16777216, r6
	ld					%0, r5
	zjmp				%:label_8

label_6:
	live				%66
	ld					%3, r3
	ld					%68436, r2
	ld					%0, r5
	zjmp				%:label_8

label_7:
	live				%66
	ld					%6, r3
	ld					%1409680135, r6
	ld					%0, r5
	zjmp				%:label_8
	sti					r6, r3, r5
	sti					r1, r5, r5

label_8:
	sti					r6, r3, %:label_10

label_9:
	live				%66
	zjmp				%:label_10

label_10:
	zjmp				%65528
