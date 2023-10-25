#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: pointer to the string to be measured
 *
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (_strlen_recursion(s + 1) + 1);
}

