	.model flat
.code
_atanx87 proc C public float64:QWORD

	fld float64

	fld1
	fpatan

	ret

_atanx87 endp
end