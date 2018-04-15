.name "Underscore"
.comment "__UNDERSCORE_S__"

label_1:
	ld					%0, r2
	zjmp				%:label_15
	zjmp				%65025

label_2:
	live				%-42
	sti					r10, r11, r13
	add					r12, r13, r13
	xor					r13, %-255, r14
	zjmp				%:label_3
	ld					%0, r14
	zjmp				%65503

label_3:
	ld					%0, r13
	zjmp				%65493

label_4:
	live				%-42
	ld					%-128, r6
	fork				%:label_5
	ld					%190056198, r7
	ld					%0, r5
	ld					%0, r16
	zjmp				%65500

label_5:
	ld					%84541307, r7
	ld					%4, r5
	ld					%190056198, r16

label_6:
	st					r16, -490

label_7:
	st					r7, -491
	ld					%0, r2
	zjmp				%65025
	lldi				%42, %42, r16
	live				%-42
	sti					r1, %:label_2, %1
	ld					%57672959, r10
	ld					%-30, r11
	ld					%-5, r12
	st					r1, 6
	live				%-42

label_8:
	fork				%65360
	ld					%-165, r13
	ld					%0, r2
	zjmp				%65514
	sti					r1, %:label_10, %1
	sti					r1, %:label_12, %1

label_9:
	fork				%65459
	st					r1, 6
	live				%:label_8
	or					r1, r1, r7
	ld					%1880161814, r9
	ld					%1879571989, r10
	ld					%34209281, r11
	fork				%:label_12

label_10:
	live				%:label_9
	fork				%:label_11
	ld					%0, r2
	zjmp				%:label_18

label_11:
	ld					%191104768, r7
	ld					%5, r6
	ld					%0, r2
	zjmp				%:label_14

label_12:
	live				%:label_10
	fork				%:label_13
	ld					%101056768, r7
	ld					%9, r6
	ld					%0, r2
	zjmp				%:label_14

label_13:
	ld					%0, r2
	ld					%12, r6
	ld					%0, r2
	zjmp				%:label_14

label_14:
	st					r1, 6
	live				%-42
	sti					r7, r6, %317
	ld					%0, r2
	zjmp				%309

label_15:
	sti					r16, %:label_20, %1
	fork				%:label_19
	ld					%:label_17, r16
	sti					r16, %:label_20, %1
	st					r1, 6

label_16:
	live				%-42

label_17:
	ld					%0, r2
	zjmp				%511

label_18:
	ld					%16, r12
	add					r12, r9, r9
	add					r12, r10, r10
	add					r12, r11, r11
	st					r1, 6
	live				%:label_16
	ld					%0, r2
	sti					r1, %:label_4, %1
	sti					r9, %:label_6, %1
	sti					r10, %:label_7, %1
	sti					r11, %:label_4, %6
	fork				%65095
	zjmp				%65295
	ld					%16777216, r16
	sti					r16, %:label_1, %6
	st					r1, 117
	sti					r1, %:label_21, %1
	ld					%507, r4
	ld					%507, r6
	st					r1, 6
	live				%-42

label_19:
	ld					%190055170, r8
	ld					%67699190, r9
	st					r8, 511
	st					r9, 510

label_20:
	ld					%24, r8
	fork				%65158
	fork				%:label_22

label_21:
	live				%-1
	ld					%0, r2
	ld					%190055682, r3
	ld					%190056194, r5
	ld					%190056194, r7
	ld					%0, r16
	zjmp				%448

label_22:
	live				%0
	ld					%4, r2
	ld					%101253622, r3
	ld					%134807571, r5
	ld					%134807571, r7
	ld					%0, r16
	zjmp				%405
