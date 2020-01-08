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
	stack_t *current = *stack;

	if (current && current->next)
	{
		(current->next)->n = current->n + (current->next)->n;
		pop(stack, pack.n);
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

/**
 * sub - The opcode sub substract the top two elements of the stack.
 * it simply multiply the first node value by "-1" and calls
 * "add" command function
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current && current->next)
	{
		current->n *= -1;
		add(stack, line_number);
	}
	else
	{
		freeStack(stack);
		free(pack.cmd);
		dprintf(2, "L%d: can't sub, stack too short", line_number);
		error("", 0, 1);
	}
}

/**
 * divs - The opcode div divide the top two elements of the stack.
 * it simply divide the nodes, store the result on one node,
 * the other one is set to zero, and calls the "add" command function
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void divs(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	char *msg;

	if (current && current->next && (current->n != 0))
	{
		current->n = (current->next)->n / current->n;
		(current->next)->n = 0;
		add(stack, line_number);

		return;
	}

	if (current && current->n == 0)
		msg = "L%d: division by zero";
	else
		msg = "L%d: can't div, stack too short";

	freeStack(stack);
	free(pack.cmd);
	dprintf(2, msg, line_number);
	error("", 0, 1);
}

/**
 * mul - The opcode mul multiply the top two elements of the stack.
 * it simply multiply the nodes, store the result on one node,
 * the other one is set to zero, and calls the "add" command function
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current && current->next && (current->n != 0))
	{
		current->n = (current->next)->n * current->n;
		(current->next)->n = 0;
		add(stack, line_number);
	}
	else
	{
		freeStack(stack);
		free(pack.cmd);
		dprintf(2, "L%d: can't mul, stack too short", line_number);
		error("", 0, 1);
	}
}
