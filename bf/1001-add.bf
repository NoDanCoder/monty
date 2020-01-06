,		; get first input in Bit0
>		; move to Bit1
,		; get second input to Bit1
[
    < +		; add 1 to Bit0
    > -		; sub 1 to Bit1
]

+++++ +++	; set Bit1 to 8
[
    < ----- -	; sub 6 to Bit0
    > -		; sub 1 to Bit1
]
< .		; print Bit0
