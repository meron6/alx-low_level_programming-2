#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random passwords for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
    int i, sum, n;
    char c;

    srand(time(NULL));
    sum = 0;
    i = 0;
    while (sum < 2772 - 122)
    {
        n = rand() % 10 + 48;
        c = (char)n;
        putchar(c);
        sum += c;
        i++;
    }
    n = 2772 - sum;
    putchar(n);
    i++;
    return (0);
}

