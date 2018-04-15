.name "Candy"
.comment ""
	st					r1, r12

label_1:
	ld					%0, r14
	zjmp				%:label_5
	st					r9, -256
	st					r10, -256
	st					r14, -9
	st					r4, -21
	st					r14, :label_1
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256

label_2:
	st					r4, -256
	st					r4, -256
	st					r9, -256
	st					r10, -256
	st					r14, -9
	st					r4, -21
	st					r14, :label_2
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r4, -256

label_3:
	st					r4, -256
	st					r4, -256
	st					r4, -256
	st					r10, -256
	st					r14, -9
	st					r4, -21
	st					r14, :label_3
	ld					%0, r15
	zjmp				%65319

label_4:
	live				%42
	fork				%:label_7
	ld					%0, r16
	zjmp				%:label_5

label_5:
	live				%42
	ld					%57672449, r3
	ld					%57672959, r4
	ld					%42991616, r9
	ld					%235536380, r10
	ld					%16777216, r11
	xor					r12, r14, r15
	sti					r15, %:label_6, %1
	sti					r15, %:label_4, %1
	sti					r15, %:label_8, %1
	zjmp				%:label_6

label_6:
	live				%42
	fork				%65224
	fork				%:label_9
	ld					%0, r15
	zjmp				%65431

label_7:
	st					r3, 256
	st					r3, 256
	st					r3, 256
	live				%1
	st					r3, 256
	st					r3, 256
	st					r3, 256
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, :label_9
	st					r3, :label_10
	st					r3, 256
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, 256
	st					r3, 256
	st					r3, 256
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, 256
	live				%1
	st					r3, 256
	zjmp				%65346
	live				%42
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	st					r9, 256
	zjmp				%65416

label_8:
	live				%1

label_9:
	live				%1

label_10:
	fork				%65403
	st					r4, 254
	zjmp				%65523
