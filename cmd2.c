#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "monty.h"

#define IGNORE (void)

/**
 * add - The opcode add adds the top two elements of the stack.
 * deletes it, and push a new one with the result
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *current = *stack;
	char buffer[256];

	if (current && current->next)
	{
		result = current->n + (current->next)->n;

		pop(stack, pack.n);
		pop(stack, pack.n);

		bzero(buffer, 256);
		sprintf(buffer, "push %d", result);

		/**
		 * important understand what below line does it mean
		 * because "push" function calls strtok(NULL, " \n")
		 * to get the integer value from "buffer"
		 */
		strtok(buffer, " \n");

		push(stack, pack.n);
	}
	else
	{
		freeStack(stack);
		free(pack.cmd);
		dprintf(2, "L%d: can't add, stack too short", line_number);
		error("", 0, 1);
	}
}

/**
 * nop - It does... basicaly... nothing :V
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: idk, does pc explode? no one know :v
 */
void nop(stack_t **stack, unsigned int line_number)
{
	IGNORE stack;
	IGNORE line_number;
}
