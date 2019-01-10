/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:18:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/06 22:19:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_core.h"
#include "converter.h"
#include "libft.h"

char	*convert_pointer(t_printf *data, t_arg *arg)
{
	arg->flags |= F_HASH;
	arg->length_modifier = ft_idxof('l', LEN_MD_CHRS);
	return (convert_u_integer_hexa(data, arg));
}
