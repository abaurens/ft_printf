/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exotic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:40:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 18:24:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/libft.h"

char				*intmax_binary(t_printf *const data, t_arg *const arg)
{
	uintmax_t		v;
	char			*tab;
	int				len;

	v = (uintmax_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*size_binary(t_printf *const data, t_arg *const arg)
{
	size_t			v;
	char			*tab;
	int				len;

	v = (size_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*ssize_binary(t_printf *const data, t_arg *const arg)
{
	ssize_t			v;
	char			*tab;
	int				len;

	v = (ssize_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*ptrdiff_binary(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t		v;
	char			*tab;
	int				len;

	v = (ptrdiff_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*quad_binary(t_printf *const data, t_arg *const arg)
{
	u_quad_t		v;
	char			*tab;
	int				len;

	v = (u_quad_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "01")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (flag(arg, F_HASH) && v != 0 && arg->prec < (len + 2))
		arg->prec += ((len + 2) - arg->prec);
	if (!(tab = padded_ulltoa_bin(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'b';
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
