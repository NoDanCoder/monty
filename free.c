#include <stdlib.h>
#include "monty.h"

/**
 * freeStack - It frees the entire stack
 * @stack: stack where this function will operate
 *
 *
 * Return: nothing
 * On error: nothing
 */
void freeStack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = current->next;
		free(current);
	}
}
