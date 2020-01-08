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

	if (current && current->n == 0)
		msg = "L%d: division by zero";
	else
		msg = "L%d: can't mod, stack too short";

	freeStack(stack);
	free(pack.cmd);
	dprintf(2, msg, line_number);
	error("", 0, 1);
}


/**
 * pchar - The opcode pchar prints the value at the top of the
 * stack in ASCII, followed by a new line.
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char *msg;

	if (*stack)
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
		{
			printf("%c\n", (*stack)->n);
			return;
		}
		else
			msg = "L%d: can't pchar, value out of range";
	else
		msg = "L%d: can't pchar, stack empty";

	freeStack(stack);
	free(pack.cmd);
	dprintf(2, msg, line_number);
	error("", 0, 1);
}

/**
 * pstr - The opcode pstr prints the string starting at the top
 * of the stack, followed by a new line.
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	IGNORE line_number;

	for (; curr; curr = curr->next)
		if (curr->n > 0 && curr->n <= 127)
			putchar(curr->n);
		else
			break;
	putchar('\n');
}

/**
 * rotl - The top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int value = 0;
	IGNORE line_number;

	for (; curr && curr->next; curr = curr->next)
	{
		value = curr->n;
		curr->n = (curr->next)->n;
		(curr->next)->n = value;
	}
}

/**
 * rotr - The last element of the stack becomes the top element of
 * the stack
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int value = 0;
	IGNORE line_number;

	while (curr && curr->next)
		curr = curr->next;

	for (; curr && curr->prev; curr = curr->prev)
	{
		value = curr->n;
		curr->n = (curr->prev)->n;
		(curr->prev)->n = value;
	}
}
