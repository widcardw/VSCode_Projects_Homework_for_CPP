DATA_SEG SEGMENT
	VAR_A	DW	?
	VAR_B	DW	?
	VAR_S	DW	?
DATA_SEG ENDS

CODE_SEG SEGMENT
	MOV		AX, [VAR_A]
	MOV		BX, $10
	MUL		BX 
	ADD 	AX, [VAR_B]
	MOV 	VAR_S, AX
CODE_SEG ENDS