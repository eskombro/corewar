.name "MKP"
.comment "SaR ez Gg"
	sti					r1, %:label_9, %1

label_1:
	st					r1, 6
	live				%:label_10
	ld					%1, r2
	live				%45223
	ld					%1, r3
	live				%13123
	sti					r1, %:label_8, %1
	ld					%0, r15

label_2:
	live				%45223
	fork				%:label_5

label_3:
	ld					%0, r15
	add					r2, r3, r2

label_4:
	zjmp				%:label_8

label_5:
	live				%651

label_6:
	fork				%:label_7
	ld					%0, r15
	ld					%0, r15
	ld					%0, r15
	zjmp				%65507

label_7:
	live				%9814
	fork				%65476

label_8:
	live				%4902343
	st					r2, -24
	st					r2, -33
	st					r2, -42
	st					r2, -51
	st					r2, :label_6
	st					r2, -69
	st					r2, :label_4
	st					r2, -87
	st					r2, -96
	st					r2, :label_3
	st					r2, -114
	st					r2, :label_2
	st					r2, -132
	st					r2, -141
	st					r2, -150
	st					r2, -159
	st					r2, -168
	st					r2, -177
	st					r2, -186
	st					r2, -195
	st					r2, -204
	st					r2, -213
	st					r2, -222
	st					r2, :label_1
	st					r2, -240
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
	zjmp				%65256
	live				%651264
	add					r2, r3, r2
	xor					r2, %15, r4
	zjmp				%65518

label_9:
	live				%1
	zjmp				%65531
	live				%6514
	zjmp				%65502
	ld					%0, r4

label_10:
	zjmp				%65513
	live				%9751364
	ld					%0, r4
