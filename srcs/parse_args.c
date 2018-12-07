/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:21:48 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/07 14:23:02 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int const g_flags_masks[] =
{
	F_MINS,
	F_ZERO,
	F_PLUS,
	F_SPAC,
	F_HASH,
	F_COLO
};

static int		get_flags(const char *format, t_arg *arg)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	i = -1;
	while ((c = FLAGS_V[++i]))
	{
		if (format[j] == c && (++j))
		{
			arg->flags |= g_flags_masks[i];
			i = -1;
		}
	}
	return (j);
}

static int		get_chain_format(const char *format, t_printf *data, int *val)
{
	int			i;

	i = 0;
	*val = 0;
	while (format[i] && (format[i] >= '0' && format[i] <= '9'))
		i++;
	if (i <= 0)
	{
		if (format[i] == '$' || data->use_chain_format == TRUE)
			return (-1);
		data->use_chain_format = FALSE;
		return (0);
	}
	if (format[i] != '$' && data->use_chain_format == MAYBE)
	{
		data->use_chain_format = FALSE;
		return (0);
	}
	if (format[i] != '$' || data->use_chain_format == FALSE)
		return (-1);
	data->use_chain_format = TRUE;
	*val = ft_atoi(format);
	return (i + 1);
}

static int		get_min_width(const char *format, t_printf *data, t_arg *arg)
{
	int			i;
	const char	*f;

	i = 0;
	f = format;
	format += get_flags(format, arg);
	if ((arg->min_width = 0) || *format == '*')
	{
		if ((i = get_chain_format(format + 1, data, &arg->min_width_idx)) < 0)
			return (0);
		++i;
		return ((format + i) - f);
	}
	arg->min_width = ft_atoi(format);
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	return ((format + i) - f);
}

static int		get_precision(const char *format, t_printf *data, t_arg *arg)
{
	int			i;
	const char	*f;

	i = 0;
	f = format;
	format += get_flags(format, arg);
	if ((arg->precision = 0) || *format++ != '.')
		return (0);
	if (*format == '*')
	{
		if ((i = get_chain_format(format + 1, data, &arg->precision_idx)) < 0)
			return (0);
		++i;
		return ((format + i + 1) - f);
	}
	while (format[i] && format[i] >= '0' && format[i] <= '9')
		i++;
	arg->precision = ft_atoi(format);
	return ((format + i + 1) - f);
}

static int		get_length_modifier(const char *frm, t_printf *data, t_arg *arg)
{
	char		c;
	int			i;
	int			j;

	j = 0;
	i = -1;
	(void)data;
	while ((c = LEN_MD[++i]))
	{
		j += get_flags(frm + j, arg);
		if (frm[j] == c && (++j))
		{
			i = -1;
		}
	}
	return (j);
}

static int		(*g_funcs[])(const char *, t_printf *, t_arg *) =
{
	get_min_width,
	get_precision,
	get_length_modifier
};

int				parse_arg(const char **format, t_printf *data, t_arg *arg)
{
	int			i;
	const char	*f;

	i = 0;
	f = *format;
	arg->flags = 0;
	*format += get_flags(*format + 1, arg) + 1;
	if ((i = get_chain_format(*format, data, &arg->flag_idx)) >= 0)
		*format += i;
	i = 0;
	while (i < 3)
		*format += g_funcs[i++](*format, data, arg);
	arg->conv_c = *(*format)++;
	arg->conv_id = -1;
	if (ft_contains(arg->conv_c, CONV_V))
		arg->conv_id = ft_idxof(arg->conv_c, CONV_V);
	return (*format - f);
}