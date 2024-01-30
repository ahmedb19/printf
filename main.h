#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct paramaters - parameters struct
 *
 * @unsign - unsigned value flag
 *
 * @plus_flag: True if plus_flag was specified
 * @space_flag: True if hashtag_flag was specified
 * @zero_flag: True if _flag was specified
 * @minus_flag: True if _flag was specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: True if h_modofier is specified
 * @l_modifier: True if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign   : 1;

	unsigned int plus_flag: 1;
	unsigned int space_flag: 1;
	unsigned int hashtag_flag: 1;
	unsigned int zero_flag: 1;
	unsigned int minus_flag: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier: 1;
	unsigned int l_modifier: 1;
} params_t;



/**
 * struct specifier - Specifier
 *@specifier: Format specifier
 *@f: Associated function
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);

int print_char(va_list arg, params_t *params);
int print_int(va_list arg, params_t *params);
int print_string(va_list arg, params_t *params);
int print_percent(va_list arg, params_t *params);
int print_S(va_list arg, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list arg, params_t *params);
int print_address(va_list arg, params_t *params);

int (*get_specifier(char *s))(va_list arg, params_t *params);
int get_print_func(char *s, va_list arg, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list arg);

int print_hex(va_list arg, params_t *params);
int print_HEX(va_list arg, params_t *params);
int print_binary(va_list arg, params_t *params);
int print_octal(va_list arg, params_t *params);

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list arg, params_t *params);
int print_rot13(va_list arg, params_t *params);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_nrs(char *str, params_t *params);
int print_nls(char *str, params_t *params);

void init_params(params_t *params, va_list arg);

char *get_precision(char *p, params_t *params, va_list arg);

int _printf(const char *format, ...);

#endif
