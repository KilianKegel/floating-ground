
.code
_sinx87 proc public

	local float64:QWORD

	movsd float64,xmm0

	fld float64

	fsin

	fst float64

	movsd xmm0,float64

	ret

_sinx87 endp
end