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

/**
 *print_rev - prints string in rev
 *@arg: string
 *@params: the parameters struct
 *
 *Return: number bytes printed
 */
int print_rev(va_list arg, params_t *params)
{
	int len, i = 0;
	char *str = va_arg(arg, char*);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			i += _putchar(*str);
	}
	return (i);
}

/**
 *print_rot13 - prints string in rot13
 *@arg: string
 *@params: parameters struct
 *
 * Return: Number of bytes printed
 */
int print_rot13(va_list arg, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMA      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(arg, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
			|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
