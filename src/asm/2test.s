.name "Presout"
.comment "HA HA HA HA HA HA HA HA HA"

label_1:
	and					%10, %10, r1
	ld					0, r1
	live				%0
	live				%:label_1
	live				%13
	live				%13
