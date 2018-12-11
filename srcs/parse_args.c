/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:21:48 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 18:56:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "converter.h"
#include "parser.h"
#include "libft.h"

int				parse_arg(const char **format, t_printf *data, t_arg *arg)
{
	int			i;
	const char	*f;

	i = 0;
	f = (*format)++;
	while (NO_ARG[i] && **format != NO_ARG[i])
		i++;
	if (**format == '%')
	{
		arg->conv = g_converters[0];
		return (++(*format) - f);
	}
	if ((i = get_chain_format(*format, data, &arg->flag_idx)) >= 0)
		*format += i;
	i = 0;
	while (i < 3)
		*format += g_funcs[i++](*format, data, arg);
	i = 0;
	while (g_converters[i].c && g_converters[i].c != *(*format))
		i++;
	if (g_converters[i].c == *(*format))
		(*format)++;
	arg->conv = g_converters[i];
	return (*format - f);
}
