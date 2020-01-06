,			; get first input in Bit0
>			; move to Bit1
,			; get second input to Bit1

> +++++ +++		; set Bit2 to 8
[
    < ----- -		; sub 6 to Bit1
    < ----- -		; sub 6 to Bit0
    >> -		; sub 1 to Bit2
]

<<			; move to Bit0
[
    >			; move to Bit1
    [
        > +		; add 1 to Bit2
        > +		; add 1 to Bit3
        << -		; sub 1 to Bit1
    ]

    >>			; move to Bit3
    [
        << +		; add 1 to Bit1
	>> -		; sub 1 to Bit3
    ]

    <<< -		; sub 1 to Bit0
]

>>			; move to Bit2 = Result

< [-] +++++ +++		; set 8 to Bit1
[
    > +++++ +		; sub 6 to Bit2
    < -			; sub 1 to Bit1
]

> .			; print Bit2 = Result
