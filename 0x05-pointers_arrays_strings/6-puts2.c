#include "main.h"

/**
 * puts2 - prints every other character of a string, starting with the first
 * character, followed by a new line.
 * @str: string to print
 *
 * Return: void
 */

void puts2(char *str)
{
    int idx = 0;

    while ((*(str + idx) != '\0') || (*(str + idx + 1) != '\0'))
    {
        _putchar(*(str + idx));
        idx = idx + 2;
    }
    _putchar('\n');
}
