
.code
_atanx87 proc public

	local float64:QWORD

	movsd float64,xmm0

	fld float64

	fld1
	fpatan

	fst float64
			fsub st(0),st(0)

	movsd xmm0,float64

	ret

_atanx87 endp
end