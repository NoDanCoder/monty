#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * built_in - checks if cmd is a command function
 * and calls his respective function to habdle
 * the stack_t
 * @head: stack to operate with cmd
 *
 * Return: On fail 0
 */
void built_in(stack_t **head)
{
	instruction_t ops[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", divs}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {"queue", queue},
		{"stack", stack}
	};

	int i = sizeof(ops) / sizeof(ops[0]); /* lenght of ops array */
	char *buffer = strtok(pack.cmd, " \n\t");

	if (buffer == NULL || *buffer == '#')
		return;

	while (i--)
		if (!strcmp(buffer, ops[i].opcode))
		{
			ops[i].f(head, pack.n);
			return;
		}

	dprintf(2, "L%d: unknown instruction %s\n", pack.n, buffer);
	free(pack.cmd);
	freeStack(head);
	fclose(pack.fdcode);
	exit(EXIT_FAILURE);
}
