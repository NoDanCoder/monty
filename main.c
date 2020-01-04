#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int ac, char *av[])
{
	FILE *montyfd;
	size_t buffSize = 0;
	stack_t *head = NULL;

	pack.cmd = NULL, pack.n = 1;

	if (ac != 2 || av == NULL)
		error("USAGE: monty file", 0, 0);

	montyfd = fopen(av[1], "r");
	if (!montyfd)
		error(str_concat("Error: Can't open file ", av[1]), 1, 0);
	pack.fdcode = montyfd;

	while (-1 != getline(&pack.cmd, &buffSize, montyfd))
		built_in(&head), pack.n++;

	freeStack(&head);
	free(pack.cmd);
	fclose(montyfd);

	return (EXIT_SUCCESS);
}