#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "monty.h"

#define IGNORE (void)

/**
 * stack - Set the mode to stack, instead of queue
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void stack(stack_t **stack, unsigned int line_number)
{
	IGNORE stack;
	IGNORE line_number;

	pack.mode = 0;
}

/**
 * queue - Set the mode to queue, instead of stack
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void queue(stack_t **stack, unsigned int line_number)
{
	IGNORE stack;
	IGNORE line_number;

	pack.mode = 1;
}
