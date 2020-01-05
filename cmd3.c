#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "monty.h"

#define IGNORE (void)

/**
 * mod - The opcode mod module the top two elements of the stack.
 * it simply module the nodes, store the result on one node,
 * the other one is set to zero, and calls the "add" command function
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	char *msg;

	if (current && current->next && (current->n != 0))
	{
		current->n = (current->next)->n % current->n;
		(current->next)->n = 0;
		add(stack, line_number);

		return;
	}

	if (current->n == 0)
		msg = "L%d: division by zero";
	else
		msg = "L%d: can't mod, stack too short";

	freeStack(stack);
	free(pack.cmd);
	dprintf(2, msg, line_number);
	error("", 0, 1);
}
