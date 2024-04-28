	.model flat
.code
_cosx87 proc C public

	local float64:QWORD

	finit

	movsd float64,xmm0

	fld float64

	fcos

;	fst float64

;	movsd xmm0,float64

	ret

_cosx87 endp
end