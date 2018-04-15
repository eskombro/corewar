.name "helltrain"
.comment "choo-choo, motherf*****s !"
	sti					r1, %:label_5, %1
	sti					r1, %:label_5, %1
	sti					r1, %:label_6, %1

label_1:
	sti					r1, %:label_4, %1
	sti					r1, %:label_8, %1
	sti					r1, %:label_8, %9
	sti					r1, %:label_8, %17

label_2:
	sti					r1, %:label_9, %1
	sti					r1, %:label_9, %2
	sti					r1, %:label_11, %1
	sti					r1, %:label_11, %9

label_3:
	sti					r1, %:label_10, %1
	ld					%0, r16
	fork				%:label_6

label_4:
	ld					%0, r2
	ld					%0, r16
	live				%4902343
	st					r2, -24
	st					r2, -33
	st					r2, -42
	st					r2, :label_3
	st					r2, -60
	st					r2, -69
	st					r2, -78
	st					r2, -87
	st					r2, -96
	st					r2, -105
	st					r2, :label_2
	st					r2, -123
	st					r2, -132
	st					r2, -141
	st					r2, -150
	st					r2, -159
	st					r2, -168
	st					r2, :label_1
	st					r2, -186
	st					r2, -195
	st					r2, -204
	st					r2, -213
	st					r2, -222
	st					r2, -231
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
	zjmp				%65242

label_5:
	live				%4239423
	fork				%65531
	ld					%0, r16
	live				%3442302
	zjmp				%65516

label_6:
	live				%4320423
	zjmp				%:label_7

label_7:
	fork				%65528

label_8:
	live				%4329034
	fork				%:label_11
	live				%3401123
	fork				%:label_10
	live				%4590543
	fork				%:label_12

label_9:
	ld					%0, r2
	ld					%251883523, r3
	ld					%0, r16
	live				%4930423
	ld					%0, r16
	zjmp				%:label_13

label_10:
	live				%4342342
	fork				%65140
	ld					%251883523, r2
	ld					%386101251, r3
	ld					%0, r16
	ld					%0, r16
	zjmp				%:label_13

label_11:
	live				%4239013
	fork				%65432
	live				%4093282
	fork				%65390
	ld					%-65280, r2
	ld					%436432899, r3
	ld					%0, r16
	ld					%0, r16
	ld					%0, r16
	zjmp				%:label_13

label_12:
	ld					%57672192, r2
	ld					%318992387, r3
	ld					%0, r16
	zjmp				%:label_13

label_13:
	st					r2, 15
	st					r3, -1
	live				%0
