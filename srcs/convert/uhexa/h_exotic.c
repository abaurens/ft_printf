/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_exotic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:57:11 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 18:24:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/ft_core.h"
#include "core/ft_types.h"
#include "core/libft.h"

char				*intmax_hexa(t_printf *const data, t_arg *const arg)
{
	uintmax_t		v;
	int				len;
	char			*tab;

	v = (uintmax_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*size_hexa(t_printf *const data, t_arg *const arg)
{
	size_t			v;
	int				len;
	char			*tab;

	v = (size_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*ssize_hexa(t_printf *const data, t_arg *const arg)
{
	ssize_t			v;
	int				len;
	char			*tab;

	v = (ssize_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*ptrdiff_hexa(t_printf *const data, t_arg *const arg)
{
	ptrdiff_t		v;
	int				len;
	char			*tab;

	v = (ptrdiff_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}

char				*quad_hexa(t_printf *const data, t_arg *const arg)
{
	u_quad_t		v;
	int				len;
	char			*tab;

	v = (u_quad_t)arg->val.i;
	if ((len = ft_unsignedlen_base(v, "0123456789abcdef")) > arg->prec)
		arg->prec = len;
	if (flag(arg, F_HASH) && v != 0)
		arg->prec += 2;
	if (flag(arg, F_ZERO) && arg->min > arg->prec)
		arg->prec = arg->min;
	if (!(tab = padded_ulltoa_hexa(v, arg->prec, arg->min, flag(arg, F_MINS))))
		return (NULL);
	if (flag(arg, F_HASH) && v != 0)
		tab[ft_idxof('0', tab) + 1] = 'x';
	if (ft_isupper(arg->conv.c))
		ft_strupcase(tab);
	insert_buffer(data, tab, ft_strlen(tab));
	free(tab);
	return (data->buf);
}
