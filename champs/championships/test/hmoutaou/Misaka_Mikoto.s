.name "Misaka Mikoto"
.comment "Misaka Mikoto (御坂 美琴 Misaka Mikoto) (born May 2) is a main heroine in Toaru Majutsu no Index and the main protagonist of Toaru Kagaku no Railgun. Introduced in the first volume of the light novels, her role in the story was later expanded in the third volume as well as the release of the Toaru Kagaku no Railgun manga, making her the main heroine of the science side and the second main heroine of the series.

	She is the third ranked Level 5 esper in Academy City, and is nicknamed the Railgun due to her signature move. Kamijou Touma coined the nickname Biri-Biri (ビリビリ?) (a Japanese onomatopoeia imitating the sound of electricity) for her and whenever the two meet he usually calls her that, even after his amnesia"

label_1:
	sti					r1, %:label_25, %1
	sti					r1, %:label_4, %1
	sti					r1, %:label_5, %1
	sti					r1, %:label_8, %1
	sti					r1, %:label_11, %1
	st					r2, :label_1
	fork				%:label_2
	add					r3, r3, r3
	zjmp				%:label_29
	zjmp				%:label_25
	zjmp				%:label_25
	zjmp				%:label_25
	zjmp				%:label_25
	zjmp				%:label_25
	zjmp				%:label_25

label_2:
	live				%404
	add					r3, r3, r3
	fork				%:label_3
	zjmp				%:label_4

label_3:
	zjmp				%:label_5

label_4:
	live				%404
	fork				%:label_6
	zjmp				%:label_8

label_5:
	live				%404
	fork				%:label_7
	zjmp				%:label_9

label_6:
	zjmp				%:label_10

label_7:
	zjmp				%:label_11

label_8:
	live				%404
	fork				%:label_12
	zjmp				%:label_21

label_9:
	live				%:label_31
	fork				%:label_13
	zjmp				%:label_16

label_10:
	live				%404
	fork				%:label_15
	zjmp				%:label_19

label_11:
	live				%404
	fork				%:label_14
	zjmp				%:label_18

label_12:
	zjmp				%:label_23

label_13:
	zjmp				%:label_17

label_14:
	zjmp				%:label_20

label_15:
	zjmp				%:label_24

label_16:
	ld					%-498, r9
	ldi					%0, %:label_26, r8
	add					r3, r3, r3
	zjmp				%:label_25

label_17:
	ld					%-504, r9
	ldi					%0, %:label_26, r8
	add					r3, r3, r3
	zjmp				%:label_25

label_18:
	ld					%508, r9
	ldi					%0, %:label_27, r8
	add					r3, r3, r3
	zjmp				%:label_25

label_19:
	ld					%516, r9
	ldi					%0, %:label_27, r8
	add					r3, r3, r3
	zjmp				%:label_25

label_20:
	ld					%512, r9
	ldi					%0, %:label_27, r8
	add					r3, r3, r3
	zjmp				%:label_25

label_21:
	ld					%:label_22, r9
	ldi					%8, %:label_25, r8
	add					r3, r3, r3

label_22:
	zjmp				%:label_25

label_23:
	ld					%11, r9
	ldi					%0, %:label_25, r8
	add					r3, r3, r3
	zjmp				%:label_25

label_24:
	ld					%15, r9
	ldi					%4, %:label_25, r8
	add					r3, r3, r3
	zjmp				%:label_25

label_25:
	live				%777
	sti					r8, %:label_25, r9
	sti					r8, %:label_25, r9
	sti					r8, %:label_25, r9
	sti					r8, %:label_25, r9
	sti					r8, %:label_25, r9
	sti					r8, %:label_25, r9
	sti					r8, %:label_25, r9
	sti					r8, %:label_25, r9

label_26:
	fork				%65486

label_27:
	zjmp				%0

label_28:
	live				%404

label_29:
	ldi					%0, %:label_28, r3
	ldi					%:label_30, %0, r2

label_30:
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256

label_31:
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	st					r2, 256
	live				%404
	st					r3, 256
