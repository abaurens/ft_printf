/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:20:27 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/21 19:04:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"

t_bflt		*new_bflt(const char *value)
{
	t_bflt	*res;

	if (!(res = (t_bflt *)malloc(sizeof(t_bflt))))
		return (NULL);
	if (!set_bflt(res, value))
		return (NULL);
	return (res);
}

void		unset_bflt(t_bflt *const num)
{
	if (!num)
		return ;
	if (num->entl)
		free(num->ent);
	if (num->decl)
		free(num->dec);
	num->entl = 0;
	num->decl = 0;
}

void		del_bflt(t_bflt const *const num)
{
	if (num)
	{
		if (num->entl)
			free(num->ent);
		if (num->decl)
			free(num->dec);
	}
	free((void *)num);
}
