.name "Ultima"
.comment " Je Suis le Prédateur, tu est Ma Proie"

label_1:
	st					r1, :label_3
	ld					%151068160, r1
	st					r1, :label_1
	ld					%:label_10, r2
	ld					%100, r3
	live				%0
	fork				%:label_2
	ld					%34144757, r4
	st					r4, r5
	ld					%50921567, r6
	st					r6, r7
	st					r6, r12
	st					r6, r13
	st					r6, r14
	st					r6, r15
	st					r4, r8
	st					r4, r9
	st					r4, r10
	ld					%167685120, r11
	ld					%4, r1
	sub					r16, r16, r16
	zjmp				%:label_11

label_2:
	ld					%190055681, r4
	ld					%190055937, r5
	ld					%190057473, r6
	ld					%190057729, r12
	ld					%190057985, r13
	ld					%190058241, r14
	ld					%190056193, r15
	ld					%190056449, r7
	ld					%190056705, r8
	ld					%190056961, r9
	ld					%151087617, r10
	ld					%151035392, r11
	ld					%0, r1
	zjmp				%:label_11
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	aff					r2

label_3:
	aff					r2
	live				%0
	live				%0
	live				%0
	zjmp				%:label_4
	aff					r2
	aff					r2
	aff					r2
	aff					r2
	live				%0
	live				%0
	live				%0

label_4:
	ld					:label_3, r5
	st					r5, 6
	live				%1
	st					r16, :label_1
	ld					%0, r6
	ld					%0, r7
	ld					%0, r8
	ld					%0, r11
	ld					%0, r12
	ld					%0, r13
	ld					%0, r14
	ld					%0, r15
	and					r1, r1, r16
	zjmp				%:label_5
	fork				%:label_7
	ld					%190055684, r5
	ld					%190055684, r9
	ld					%190056708, r10
	ld					%10, r4
	sub					r16, r16, r16
	zjmp				%:label_9

label_5:
	fork				%:label_8
	ld					%84149761, r5
	ld					%151259145, r10
	st					r5, r9
	ld					%:label_6, r4
	sub					r16, r16, r16

label_6:
	zjmp				%:label_9

label_7:
	ld					%0, r7
	st					r5, r9
	ld					%32768000, r10
	aff					r1
	ld					%16, r4
	sub					r16, r16, r16
	zjmp				%:label_9

label_8:
	live				%1
	ld					%151587073, r5
	st					r5, r9
	st					r9, r10
	ld					%511, r4
	sub					r16, r16, r16
	zjmp				%:label_9

label_9:
	ld					%495, r8

label_10:
	add					r16, r16, r16
	sti					r10, r8, r4
	zjmp				%500
	aff					r4
	aff					r4
	aff					r4
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0
	live				%0

label_11:
	sti					r4, r1, %505
	zjmp				%499
