#include "main.h"

/**
 *print_from_to - prints a range of char addresses
 *@start: starting address
 *@stop: stopping address
 *@except: except address
 *
 *Return: Number of bytes printed
 */

int print_from_to(char *start, char *stop, char *except)
{
	int i = 0;

	while (start <= stop)
	{
		if (start != except)
			i += _putchar(*start);
		start++;
	}
	return (i);
}
