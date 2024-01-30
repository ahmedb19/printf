#include "main.h"

/**
 *_printf - Prints anything
 *@format - Format string
 *
 *Return: Number of bytes printed
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list arg;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(arg, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && format[2])
		return (-1);
	for (p = (char *) format; *p; p++)
	{
		init_params(&params, arg);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, arg);
		p = get_precision(p, &params, arg);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, arg, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(arg);
	return (sum);
}
