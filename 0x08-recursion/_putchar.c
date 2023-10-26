#include <unistd.h>

/**
 * This is my __putchar.c
 */

int _putchar(char c)
{
	return write(STDOUT_FILENO, &c, 1);
}
