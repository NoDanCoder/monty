#include <stdlib.h>
#include "monty.h"

void freeStack(stack_t **stack)
{
	stack_t *current = *stack;
	
	for (; current; current = *stack)
	{
		*stack = current->next;
		free(current);
	}
}
