.name "loose"
.comment "loooose"

label_1:
	fork				%2048
	sti					r1, %:label_5, %1
	sti					r1, %:label_6, %1

label_2:
	sti					r1, %:label_6, %16

label_3:
	sti					r1, %:label_5, %1
	st					r2, :label_2

label_4:
	st					r2, -13

label_5:
	live				%53165
	st					r2, :label_4
	st					r2, :label_4
	st					r2, -24
	st					r2, -33
	st					r2, :label_3
	st					r2, -51
	st					r2, -60
	st					r2, -69
	st					r2, -78
	st					r2, -87
	st					r2, :label_1
	st					r2, -105
	st					r2, -114
	st					r2, -123
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
	zjmp				%65246
	ld					%0, r2

label_6:
	live				%654664
	ld					%0, r2
	fork				%65224
	live				%354534
	fork				%65216
	zjmp				%65513
	live				%65468435
	ld					%0, r2
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	st					r2, 511
	zjmp				%64898
