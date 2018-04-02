.name "Douceur-power"
.comment "La douceur de la quenelle"

label_1:
	st					r1, 7
	ld					%4242, r1
	st					r2, :label_1
	sti					r2, %:label_1, %1
	fork				%:label_4
	sti					r1, %:label_3, %1
	sti					r1, %:label_7, %1
	ld					%252645135, r9
	ld					%-255, r10
	ld					%655202, r12
	ld					%17432564, r15
	ld					%42991616, r16

label_2:
	ld					%0, r2

label_3:
	live				%12345
	fork				%:label_6
	live				%12345
	st					r15, -467
	st					r16, -478
	st					r1, -487
	st					r10, -496
	st					r2, -491
	st					r9, :label_2
	st					r9, -60
	st					r9, -75
	st					r9, -90
	st					r9, -105
	st					r9, -120
	st					r9, -135
	st					r9, -150
	zjmp				%65466
	live				%12345
	sti					r2, r3, r3
	zjmp				%65027

label_4:
	live				%12345
	fork				%:label_5
	ld					%-252, r3
	ld					%190055683, r2
	ld					%190056451, r5
	ld					%-12, r9
	ld					%190056457, r8
	ld					%0, r16
	zjmp				%65473

label_5:
	ld					%-250, r3
	ld					%50986499, r2
	ld					%50986499, r5
	ld					%-10, r9
	ld					%151650275, r8
	ld					%0, r16
	zjmp				%65428

label_6:
	live				%12345
	fork				%:label_15
	zjmp				%:label_7
	live				%12345
	fork				%:label_7
	live				%12345
	fork				%:label_7
	live				%12345
	fork				%:label_13
	zjmp				%65512

label_7:
	live				%12345
	fork				%:label_8
	live				%12345
	fork				%:label_10
	ld					%0, r9
	zjmp				%65486

label_8:
	live				%12345
	fork				%:label_9
	live				%12345
	ld					%190054658, r1
	ld					%6, r2
	ld					%4, r3
	ld					%0, r9
	zjmp				%:label_14

label_9:
	live				%12345
	ld					%8, r2
	ld					%4, r2
	ld					%2, r3
	ld					%0, r9
	zjmp				%:label_14

label_10:
	live				%12345
	ld					%50397184, r1
	ld					%:label_11, r2

label_11:
	ld					%:label_12, r3

label_12:
	ld					%0, r9
	zjmp				%:label_14

label_13:
	live				%12345
	ld					%1111638594, r1
	ld					%254, r2
	ld					%254, r3
	ld					%0, r9
	zjmp				%:label_14

label_14:
	sti					r1, r2, r3

label_15:
	fork				%:label_16
	ld					%242, r3
	ld					%190055683, r2
	ld					%190056451, r5
	ld					%12, r9
	ld					%190056457, r8
	ld					%0, r16
	zjmp				%:label_18

label_16:
	ld					%244, r3
	ld					%50921951, r2
	ld					%50921951, r5
	ld					%:label_17, r9
	ld					%151584787, r8

label_17:
	ld					%0, r16
	zjmp				%:label_18

label_18:
	live				%12345
	sti					r2, r3, r3
	zjmp				%479
