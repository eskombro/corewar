.name "Kappa"
.comment "AKA Kappa Sandwich."
	sti					r1, %:label_10, %1
	ld					%75, r13
	aff					r13
	fork				%:label_9
	live				%1337
	ld					%880, r5
	ld					%50327043, r6
	ld					%1879310335, r7
	ld					%16777216, r8
	ld					%17432543, r9
	st					r5, -80
	st					r6, -81
	st					r7, -82
	st					r8, -83
	st					r9, -84
	fork				%:label_8
	live				%:label_1
	fork				%:label_6
	live				%42
	fork				%:label_5
	live				%42
	fork				%:label_2
	live				%42
	fork				%:label_1
	ld					%0, r2
	zjmp				%:label_9

label_1:
	ld					%57672447, r2
	ld					%-234655741, r3
	ld					%0, r4
	live				%:label_3
	fork				%65531
	zjmp				%65359

label_2:
	live				%:label_4
	ld					%-301764605, r2
	ld					%-167546877, r3
	or					r12, r12, r12
	ld					%0, r4

label_3:
	fork				%:label_10
	live				%42
	fork				%65531

label_4:
	zjmp				%65314

label_5:
	live				%42
	ld					%-65280, r2
	ld					%-117215229, r3
	or					r12, r12, r12
	or					r12, r12, r12
	ld					%0, r4
	fork				%:label_10
	live				%42
	fork				%:label_10
	live				%:label_7
	fork				%65531
	zjmp				%65256

label_6:
	live				%42
	st					r1, r2
	ld					%-50106365, r3
	or					r12, r12, r12
	or					r12, r12, r12
	or					r12, r12, r12

label_7:
	ld					%0, r4
	fork				%:label_10
	live				%42
	fork				%:label_10
	live				%42
	fork				%:label_10
	live				%42
	fork				%65531
	zjmp				%65188

label_8:
	live				%42
	ld					%167763715, r2
	ld					%-301764605, r3
	or					r12, r12, r12
	or					r12, r12, r12
	or					r12, r12, r12
	or					r12, r12, r12
	ld					%0, r4
	fork				%:label_10
	live				%42
	fork				%:label_10
	live				%42
	fork				%:label_10
	live				%42
	fork				%:label_10
	live				%42
	fork				%65531
	zjmp				%65104

label_9:
	live				%42
	fork				%:label_16
	live				%42
	fork				%:label_15
	live				%42
	fork				%:label_12
	live				%42
	fork				%:label_11
	ld					%0, r2

label_10:
	live				%42
	zjmp				%65531

label_11:
	ld					%57672192, r2
	ld					%318992387, r3
	ld					%0, r4
	live				%:label_13
	fork				%65531
	zjmp				%:label_18

label_12:
	live				%:label_14
	ld					%251883523, r2
	ld					%386101251, r3
	or					r12, r12, r12
	ld					%0, r4

label_13:
	fork				%65465
	live				%42
	fork				%65531

label_14:
	zjmp				%:label_18

label_15:
	live				%42
	ld					%-65280, r2
	ld					%436432899, r3
	or					r12, r12, r12
	or					r12, r12, r12
	ld					%0, r4
	fork				%65415
	live				%42
	fork				%65407
	live				%:label_17
	fork				%65531
	zjmp				%:label_18

label_16:
	live				%42
	st					r1, r2
	ld					%251883523, r3
	or					r12, r12, r12
	or					r12, r12, r12
	or					r12, r12, r12

label_17:
	ld					%0, r4
	fork				%65355
	live				%42
	fork				%65347
	live				%42
	fork				%65339
	live				%42
	fork				%65531
	zjmp				%:label_18

label_18:
	st					r2, 15
	st					r3, -1
	live				%1337
