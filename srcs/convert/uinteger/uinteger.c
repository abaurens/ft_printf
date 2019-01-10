/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinteger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:25:04 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:47:56 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "uinteger.h"
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "libft.h"

static char			*uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned int	v;
	char			*tab;

	v = (unsigned int)arg->value;
	if (arg->flags & F_ZERO)
		arg->precision = arg->min_width;
	if (!(tab = padded_ulltoa(v, arg->precision, arg->min_width,
		(arg->flags & F_MINS) != 0)))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

static const t_converter	g_funcs[] =
{
	{'H', TRUE, short_short_uinteger},
	{'h', TRUE, short_uinteger},
	{' ', TRUE, uinteger},
	{'j', TRUE, intmax_uinteger},
	{'l', TRUE, long_uinteger},
	{'L', TRUE, long_long_uinteger},
	{'q', TRUE, quad_uinteger},
	{'z', TRUE, size_uinteger},
	{'Z', TRUE, ssize_uinteger},
	{'t', TRUE, ptrdiff_uinteger},
	{'\0', FALSE, NULL}
};

char				*convert_u_integer(t_printf *data, t_arg *arg)
{
	int				i;
	long long		prec;
	long long		min;

	min = arg->min_width;
	prec = arg->precision;
	i = get_arg(data, arg->flag_idx, &arg->value);
	i = (i || (arg->min_width_idx && get_arg(data, arg->min_width_idx, &min)));
	if (i || (arg->precision_idx && get_arg(data, arg->precision_idx, &prec)))
		return (NULL);
	i = 0;
	arg->min_width = (((int)min) < 0 ? 0 : (int)min);
	if ((arg->precision = (((int)prec) < 0 ? 0 : (int)prec))
		|| (arg->flags & F_MINS))
		arg->flags &= ~F_ZERO;
	while (g_funcs[i].c && g_funcs[i].c != LEN_MD_CHRS[arg->length_modifier])
		i++;
	if (!g_funcs[i].c)
		return (g_funcs[0].func(data, arg));
	return (g_funcs[i].func(data, arg));
}