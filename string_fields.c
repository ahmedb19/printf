#include "main.h"

/**
 *get_precision - gets the precision from the format string
 *@p: Format string
 *@params: Parameters struct
 *@arg: Argument pointer
 *
 * Return: new pointer
 */

char *get_precision(char *p, params_t *paramsn va_list arg)
{
	int d = 0;

	if (!p = '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(arg, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
