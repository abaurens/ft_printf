/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:28:24 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/18 19:55:12 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "core/libft.h"
#include "core/ft_types.h"
#include "core/argument_mgr.h"

static t_val		(*const g_funcs[])(va_list ap, const char t, const int l) =
{
	get_integer,
	get_pointer,
	get_double
};

static const char	*g_convs[] =
{
	"dDiuoxXcCb",
	"psSnr",
	"fFeEgGaA",
	NULL
};

static int			add_arg(t_ftlist *lst, t_val v)
{
	t_lst_elem		*new;

	if (!lst || !(new = malloc(sizeof(t_lst_elem))))
		return (1);
	new->val = v;
	new->next = NULL;
	new->prev = lst->tail;
	if (lst->tail)
		lst->tail->next = new;
	lst->tail = new;
	if (!lst->head)
		lst->head = new;
	lst->size++;
	return (0);
}

static t_lst_elem	*get_at(t_ftlist *lst, const size_t idx)
{
	size_t			i;
	t_lst_elem		*cur;

	i = 0;
	cur = lst->head;
	if (lst->size < idx)
		return (NULL);
	while (cur && ++i < idx)
		cur = cur->next;
	return (cur);
}

t_lst_elem			*get_arg_aa(t_printf *data, const size_t idx, const char t,
								const int l)
{
	int				i;

	i = 0;
	if (idx == 0 || !data)
		return (NULL);
	while (g_convs[i] && !ft_contains(t, g_convs[i]))
		i++;
	if (!g_convs[i])
		return (NULL);
	while (data->args.size < idx)
	{
		if (add_arg(&data->args, g_funcs[i](data->va_lst, t, l)))
			return (NULL);
	}
	return (get_at(&data->args, idx));
}

int					get_arg_a(t_printf *data, const size_t idx, t_arg *a)
{
	t_lst_elem		*tmp;

	if (!a || !a->conv.w_arg)
		return (!a);
	if (!(tmp = get_arg_aa(data, idx, a->conv.c, a->length_modifier)))
		return (1);
	a->val = tmp->val;
	return (0);
}

int					get_arg_i(t_printf *data, const size_t idx, int *v)
{
	t_lst_elem		*tmp;

	if (!(tmp = get_arg_aa(data, idx, 'd', 0)))
		return (1);
	if (v)
		*v = tmp->val.i;
	return (0);
}
