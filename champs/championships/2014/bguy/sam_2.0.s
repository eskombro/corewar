.name "S.A.M."
.comment "Ca roxxe du chameau"
	sti					r1, %:label_1, %1
	ld					%0, r16
	fork				%:label_2
	st					r1, 6
	live				%21
	fork				%:label_3

label_1:
	ld					%0, r2
	ld					%0, r16
	live				%4902343
	st					r2, -50
	st					r2, -59
	st					r2, -68
	st					r2, -77
	st					r2, -86
	st					r2, -95
	st					r2, -104
	st					r2, -113
	st					r2, -122
	st					r2, -131
	st					r2, -140
	st					r2, -149
	st					r2, -158
	st					r2, -167
	st					r2, -176
	st					r2, -185
	st					r2, -194
	st					r2, -203
	zjmp				%65427

label_2:
	ld					%0, r2
	live				%21
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	st					r2, 124
	zjmp				%65459

label_3:
	st					r1, 6
	live				%42
	fork				%65531
