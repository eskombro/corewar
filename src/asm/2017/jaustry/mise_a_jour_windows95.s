.name "mise_a_jour_windows95"
.comment "Votre version de windows est obselete, votre mémoire vas être mise jour, veuillez ne pas eteindre vore ordinateur au risque de voir toutes vos donnees se faire ecrasées"
	live				%1
	ld					%252645135, r2
	ld					%57672449, r3
	ld					%16777216, r5

label_1:
	fork				%:label_14
	fork				%:label_11
	sub					r4, r4, r4
	zjmp				%:label_10
	live				%1
	fork				%65025

label_2:
	st					r4, -100

label_3:
	st					r4, -100

label_4:
	st					r4, -100

label_5:
	st					r4, -100

label_6:
	st					r4, -100

label_7:
	st					r4, -100
	st					r4, -100
	st					r4, -100
	st					r4, -100
	st					r4, -100
	st					r4, -100
	st					r4, -100

label_8:
	st					r4, -100
	st					r4, -100
	st					r4, -100
	st					r4, -100
	st					r4, -100
	st					r4, -100
	st					r4, -100

label_9:
	st					r4, -100
	st					r4, :label_2
	st					r4, :label_3
	st					r4, :label_4
	st					r4, :label_5
	st					r4, :label_6
	st					r4, :label_7

label_10:
	live				%1
	st					r2, -511
	st					r2, -510
	st					r2, -509
	st					r2, -508
	st					r2, -507
	st					r2, -506
	st					r2, -505
	st					r2, -504
	st					r2, -503
	st					r2, -502
	st					r2, -501
	st					r2, -500
	st					r2, -499
	st					r2, -498
	st					r2, -497
	st					r2, -496
	st					r2, -495
	st					r2, -494
	st					r2, -493
	st					r2, -492
	live				%1
	st					r16, :label_1
	st					r16, :label_2
	st					r16, -244
	st					r16, -243
	st					r16, -242
	st					r16, :label_7
	st					r16, -238
	st					r16, -236
	st					r16, -234
	st					r16, -232
	st					r16, :label_8
	st					r16, -228
	st					r16, -226
	st					r16, -224
	st					r16, -222
	st					r16, :label_9
	st					r16, -218
	st					r16, -216
	st					r16, -214
	st					r16, -212
	zjmp				%65326

label_11:
	st					r1, -212

label_12:
	st					r1, 69

label_13:
	st					r1, -117
	st					r16, :label_11
	st					r16, :label_12
	st					r16, :label_13
	ld					%1879245026, r4
	ld					%5, r10
	live				%1
	fork				%65274
	live				%1
	fork				%65523
	live				%1
	fork				%:label_18
	sub					r4, r4, r4
	live				%1
	zjmp				%65531

label_14:
	live				%1
	ld					%495, r8
	ld					%16, r11
	ld					%-9, r12
	ld					%:label_17, r13
	ld					%269025348, r14
	ld					%0, r10
	fork				%:label_15
	ld					%4, r10
	ld					%185139211, r9
	ld					%134808042, r7
	ld					%134808042, r6
	ld					%134808042, r15
	sub					r16, r16, r16
	zjmp				%:label_16

label_15:
	ld					%190056714, r9
	ld					%190056714, r7
	ld					%190056202, r6
	ld					%190055946, r15
	zjmp				%:label_16

label_16:
	add					r13, r12, r13

label_17:
	sti					r15, r10, r13
	live				%1
	add					r14, r12, r14
	st					r14, -109
	st					r13, -121
	st					r14, 9
	and					r16, r16, r16
	zjmp				%258
	live				%1
	zjmp				%65488

label_18:
	fork				%65361
	live				%0
	add					r4, r10, r4
	st					r4, 6
	st					r3, 200
	and					r16, r16, r16
	zjmp				%65511
