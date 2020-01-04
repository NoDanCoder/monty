#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "monty.h"

/**
 * isNumber - checks if a given str, is an array of ASCII
 * digits
 * @str: string to check
 *
 *
 * Return: 1 if true, else 0
 * On error: nothing
 */
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

/**
 * error - it free and close something according to
 * values given in parameters and exit a program with
 * EXIT_FAILURE
 * @str: message to print on "stderr"
 * @shouldFree: if should free the given str
 * @closeFile: if shuold to close the file
 * (it's a global variable)
 *
 *
 * Return: exit with EXIT_FAILURE
 * On error: nohting
 */
void error(char *str, int shouldFree, int closeFile)
{
	dprintf(2, "%s\n", str);
	if (shouldFree)
		free(str);
	if (closeFile)
		fclose(pack.fdcode);
	exit(EXIT_FAILURE);
}
