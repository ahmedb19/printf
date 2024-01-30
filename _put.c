#include "main.h"

/**
 *_puts - prints a string with newline
 *@str: String to print
 *
 *Return: void
 */
int _puts(char *str)
{
	char *s = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 *_putchar - writes the character c to stdout
 *@c: Character to be printed
 *
 *Return: 1(Success), else -1 is returned, and errno is set approprietly
 */
int _putchar(int c)
{
	static int c;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

