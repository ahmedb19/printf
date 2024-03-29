#include "main.h"

/**
 *convert - converter function
 *@num: Number
 *@base: Base
 *@flags: argument flags
 *@params: parameter struct
 *
 * Return: String
 */

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 *print_unsigned - prints unsigned integer numbers
 *@arg: argument pointer
 *@params: parameters struct
 *
 *Return: Bytes printed
 */
int print_unsigned(va_list arg, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 *print_address - prints address
 *@arg: argument pointer
 *@params: parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list arg, params_t *params)
{
	unsigned long int n = va_arg(arg, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
