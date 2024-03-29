/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_long.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:41:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/02/01 15:14:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/libft.h"

char				*short_short_uinteger(t_printf *const dta, t_arg *const arg)
{
	unsigned char	v;
	char			*tab;

	v = (unsigned char)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(dta, tab, ft_strlen(tab));
	free(tab);
	return (dta->buf);
}


char				*short_uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned short	v;
	char			*tab;

	v = (unsigned short int)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}


char				*long_uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned long	v;
	char			*tab;

	v = (unsigned long int)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*long_long_uinteger(t_printf *const data, t_arg *const arg)
{
	unsigned long long	v;
	char				*tab;

	v = (unsigned long long)arg->val.i;
	if (flag(arg, F_ZERO))
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
