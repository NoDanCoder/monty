/* bf program to print "Holberton\n" */

> +++++ +++			// H start on Bit1
> +++++ +++++ +++++		// o
> +++++ +++++ ++		// l
> ++				// b
> +++++				// e
> +++++ +++++ +++++ +++		// r
> +++++ +++++ +++++ +++++	// t
> +++++ +++++ +++++		// o
> +++++ +++++ ++++		// n

[<]				// back to Bit0

/* multiply 13 * 5 = 41 and put on Bit1 */
/* print first character uppercase */

+++++ +++++ +++		// set Bit0 to 13
[
    > +++++		// add 5 to Bit1
    < -			// sub 1 to Bit0
]
> - .			// Stay Bit1 = ('A' sub 1) add 'H'

[-]			//reset Bit1 to 0

/* print whole lowercase characters */

>			// access to Bit2
[

    <			// back to previous Bit

    /* multiply 13 * 5 = 41 and put on Bit1 */
    
    +++++ +++			// set Previous Bit to 8
    [
        > +++++ +++++ ++	// add 12 to Print Bit
        < -			// sub 1 to Previous Bit
    ]
    > .				// Stay Print Bit = ('a' sub 1) add "Character"

    [-]				// reset Print Bit to 0

    >				// access next print Bit
]

+++++ +++++ .			// print new line
