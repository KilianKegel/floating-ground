	.model flat
.code
_atanx87 proc C public

	local float64:QWORD

	movsd float64,xmm0

	fld float64

	fpatan

	fst float64

	movsd xmm0,float64

	ret

_atanx87 endp
end