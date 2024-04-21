
.code
_sqrtx87 proc public

	local float64:QWORD

	movsd float64,xmm0

	fld float64

	fsqrt

	fst float64

	movsd xmm0,float64

	ret

_sqrtx87 endp
end