.name "Explosive Kitty"
.comment "Jan-ken-pon (じゃんけんぽん)
Ce qui reste éternellement incompréhensible dans la nature, c’est qu’on puisse la comprendre.
Celui qui ne peut plus éprouver ni étonnement ni surprise, est pour ainsi dire mort : ses yeux sont éteints. – Albert Einstein
Si vous voulez trouver les secrets de l'univers pensez en termes de fréquences, d'énergies et de vibrations. - Nikola Tesla
Pas la pour etre ici. - Silicon Val[list]
Dieu est la plus belle invention.
Tapis dans l'ombre je veille. - Minou"
	ld					-42, r2
	zjmp				%:label_3
	sti					r10, r15, r9
	live				%42
	zjmp				%65126
	ld					%50986512, r10
	ld					%-392, r9
	ld					%84540929, r2

label_1:
	ld					%-487, r3
	ld					%118095856, r4

label_2:
	ld					%-502, r5
	ld					%:label_2, r7
	ld					-511, r1
	zjmp				%65469

label_3:
	ld					%55575553, r8

label_4:
	st					r1, r15
	st					r8, :label_4
	fork				%:label_9

label_5:
	live				%42

label_6:
	fork				%65455
	ld					%190054913, r10

label_7:
	ld					%-396, r9
	ld					%190055425, r2
	ld					%-491, r3

label_8:
	st					r2, r4
	ld					%-506, r5
	ld					%:label_8, r7
	ld					-511, r1
	zjmp				%65388
	st					r4, -37
	st					r4, -47
	st					r4, :label_7
	st					r4, -67
	st					r4, :label_6
	st					r4, :label_5
	st					r4, -97
	st					r4, -107
	st					r4, -117
	st					r4, -127
	st					r4, -137
	st					r4, -147
	st					r4, -157
	st					r4, -167
	st					r4, -177
	st					r4, -187
	st					r4, :label_1
	st					r4, -207
	st					r4, -217
	st					r4, -227
	st					r4, -237
	st					r4, -247
	st					r4, -257
	st					r4, -267
	st					r4, -277
	st					r4, -287
	st					r4, -297
	st					r4, -307
	st					r4, -317
	st					r4, -327
	st					r4, -337
	st					r4, -347
	st					r4, -357
	st					r4, -367
	st					r4, -377
	st					r4, -387
	st					r4, -397
	st					r4, -407
	st					r4, -417
	st					r4, -427
	st					r4, -437
	st					r4, -447
	st					r4, -457
	st					r4, -467
	st					r4, -477
	live				%42
	zjmp				%65306

label_9:
	ld					%252645135, r4
	live				%:label_11
	ld					511, r1
	fork				%:label_10
	st					r15, -27
	live				%42
	zjmp				%65273

label_10:
	live				%42
	fork				%65265
	live				%42
	fork				%:label_12

label_11:
	live				%42
	fork				%:label_14
	ld					%5, r3
	ld					%511, r5
	ld					%190055429, r2
	ld					%33554431, r6
	ld					511, r1
	zjmp				%:label_16

label_12:
	live				%:label_13
	fork				%:label_15
	ld					%9, r3
	ld					%506, r5
	ld					%17519622, r2
	ld					17, r6
	ld					511, r1
	zjmp				%:label_16

label_13:
	live				%42
	sti					r2, r3, r1

label_14:
	ld					%13, r3
	ld					%501, r5
	ld					%50401039, r2
	st					r2, r6
	ld					511, r1
	zjmp				%:label_16

label_15:
	st					r15, -42
	ld					%511, r3
	ld					%496, r5
	st					r4, r2
	st					r4, r6
	zjmp				%:label_16

label_16:
	sti					r2, r3, r1
