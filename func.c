#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "monty.h"

int isNumber(char *str)
{
	if (!*(str + 1))
		return (isdigit(*str) ? 1 : 0);
	return (isdigit(*str) || (*str == '-') ? isNumber(str + 1) : 0);
}

/**
 * str_concat - function that concatenates two strings
 * into other pointer, and return this ponter
 * @s1: first string
 * @s2: second string
 *
 *
 * Return: address where is stores the result
 * On error: -1 inapropiate entry
 */

char *str_concat(char *s1, char *s2)
{
	char *arr = NULL;

	s1 = (s1) ? s1 : "";
	s2 = (s2) ? s2 : "";

	arr = malloc(((strlen(s1) + strlen(s2))  * sizeof(*arr)) + 1);

	if (!arr)
		error("Error: malloc failed", 0, 0);

	strcat(arr, s1);
	strcat(arr, s2);

	return (arr);
}

void error(char *str, int shouldFree, int closeFile)
{
	dprintf(2, "%s\n", str);
	if (shouldFree)
		free(str);
	if (closeFile)
		fclose(pack.fdcode);
	exit(EXIT_FAILURE);
}
