#include "main.h"

/**
 *get_specifier - finds the format func
 *@s: the format string
 *
 *Return: Number of bytes printed
 */
int (*get_specifier(char *s))(va_list arg, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 *get_print_func - finds the format function
 *@s: format string
 *@arg: argument pointer
 *@params: Parameters struct
 *
 *Return: Number of bytes printed
 */
int get_print_func(char *s, va_list arg, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(arg, params));
	return (0);
}

/**
 *get_flag - finds the flag func
 *@s: format string
 *@params: Parameters struct
 *
 *Return: If flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 *get_modifier - finds the modifier function
 *@s: Format string
 *@params: parameters struct
 *
 *Return: If modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 *get_width - gets the width from the format string
 *@s: Format string
 *@params: Parameters struct
 *@arg: Argument pointer
 *
 *Return: New pointer
 */

char *get_width(char *s, params_t *params, va_list arg)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(arg, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
