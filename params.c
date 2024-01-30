#include "main.h"

/**
 *init_params - clears struct fields and reset BUUFFER
 *@params: Parameters struct
 *@arg: Argument pointer
 *
 * Return: Void
 */
void init_params(params_t *params, va_list arg)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)arg;
}
