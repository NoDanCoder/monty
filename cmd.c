#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

#define IGNORE (void)

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *add, *current = *stack;
	char *value;

	add = malloc(sizeof(stack_t));
	if (!add)
	{
		freeStack(stack);
		free(pack.cmd), error("Error: malloc failed", 0, 1);
	}

	value = strtok(NULL, " \n");
	if (value && isNumber(value))
		add->n = atoi(value);
	else
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		free(add), free(pack.cmd);
		freeStack(stack);
		fclose(pack.fdcode);
		exit(EXIT_FAILURE);
	}

	if (current)
		current->prev = add;

	*stack = add;
	add->next = current;
	add->prev = NULL;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	IGNORE line_number;

	for (; current; current = current->next)
		printf("%d\n", current->n);
}

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
