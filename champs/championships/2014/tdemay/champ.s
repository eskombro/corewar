.name "lazer"
.comment "Mundo dit beaucoup son nom pour pas l'oublier, pck c deja arriver!"
	sti					r1, %:label_4, %1

label_1:
	sti					r1, %:label_9, %1
	sti					r1, %:label_7, %1
	sti					r1, %:label_10, %1
	sti					r1, %:label_6, %1

label_2:
	and					r1, %0, r1

label_3:
	ld					%100, r4
	fork				%:label_7
	zjmp				%:label_9

label_4:
	live				%1566
	fork				%:label_6
	fork				%:label_9
	zjmp				%65525

label_5:
	ld					%0, r8
	ld					%5, r15

label_6:
	live				%2
	ldi					%:label_5, r8, r16
	sti					r16, %394, r8
	add					r15, r8, r8
	sti					r16, %383, r8
	live				%3
	xor					r8, r3, r9
	zjmp				%65484
	ld					%0, r9
	zjmp				%65488

label_7:
	live				%:label_8
	ld					%1111638594, r2
	st					r2, -69
	st					r2, -74
	st					r2, -83
	st					r2, :label_5
	st					r2, -101
	st					r2, -109

label_8:
	st					r2, -115
	st					r2, -123
	st					r2, -132
	st					r2, -141
	st					r2, -150
	st					r2, :label_3
	st					r2, -168
	st					r2, :label_2
	st					r2, -186
	st					r2, -195
	st					r2, -204
	st					r2, -213
	st					r2, -222
	st					r2, -231
	st					r2, :label_1
	st					r2, -249
	st					r2, -258
	st					r2, -267
	st					r2, -276
	st					r2, -285
	st					r2, -294
	st					r2, -303
	st					r2, -312
	st					r2, -321
	st					r2, -330
	st					r2, -339
	st					r2, -348
	st					r2, -357
	st					r2, -366
	st					r2, -375
	st					r2, -384
	st					r2, -393
	st					r2, -402
	st					r2, -411
	st					r2, -420
	st					r2, -429
	st					r2, -438
	st					r2, -447
	st					r2, -456
	st					r2, -465
	st					r2, -474
	st					r2, -483
	st					r2, -492
	st					r2, -501
	st					r2, -510
	zjmp				%65269

label_9:
	ld					%4, r8
	ld					%0, r4
	ld					%1111638594, r6
	live				%99
	sti					r6, 58, r4
	add					r4, r8, r4
	sti					r6, 47, r4
	add					r4, r8, r4
	fork				%65488
	zjmp				%65485

label_10:
	live				%4242
	add					r4, r8, r4
	sti					r6, r4, %20
	add					r4, r8, r4
	sti					r6, r4, %9
	zjmp				%65509
