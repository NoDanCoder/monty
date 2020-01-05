#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "monty.h"

#define IGNORE (void)

/**
 * push - The opcode push pushes an element at the top
 * of the stack
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *add, *current = *stack;
	char *value;

	add = malloc(sizeof(stack_t));
	if (!add)
	{
		freeStack(stack), free(pack.cmd);
		error("Error: malloc failed", 0, 1);
	}
	value = strtok(NULL, " \n\t"); /* read next parameter from pack.cmd */

	if (value && isNumber(value))
		add->n = atoi(value);
	else
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		free(add), free(pack.cmd), freeStack(stack);
		fclose(pack.fdcode), exit(EXIT_FAILURE);
	}

	if (pack.mode == 0)
	{
		if (current)
			current->prev = add;
		*stack = add;
		add->next = current;
		add->prev = NULL;
	}
	else
	{
		while (current && current->next)
			current = current->next;

		if (current)
			current->next = add;
		else
			*stack = add;
		add->prev = current;
		add->next = NULL;
	}
}

/**
 * pall - The opcode pall prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	IGNORE line_number;

	for (; current; current = current->next)
		printf("%d\n", current->n);
}

/**
 * pint - The opcode pint prints the value at the top of the
 * stack, followed by a new line.
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		freeStack(stack);
		free(pack.cmd);
		dprintf(2, "L%d: can't pint, stack empty", line_number);
		error("", 0, 1);
	}
}

/**
 * pop - The opcode pop removes the top element of the stack.
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	else if (*stack)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		free(pack.cmd);
		dprintf(2, "L%d: can't pop an empty stack", line_number);
		error("", 0, 1);
	}
}


/**
 * swap - The opcode swap swaps the top two elements of the stack.
 * @stack: stack where this function will operate
 * @line_number: on error case, to print out the info
 *
 *
 * Return: nothing
 * On error: it frees some buffers and exit the program
 * with EXIT_FAILURE
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack && (*stack)->next)
	{
		*stack = current->next;
		current->next = (*stack)->next;
		current->prev = *stack;
		(*stack)->prev = NULL;
		(*stack)->next = current;
		if (current->next)
			(current->next)->prev = current;
	}
	else
	{
		freeStack(stack);
		free(pack.cmd);
		dprintf(2, "L%d: can't swap, stack too short", line_number);
		error("", 0, 1);
	}
}
