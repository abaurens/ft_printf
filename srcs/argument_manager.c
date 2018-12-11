/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:28:24 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/11 20:38:45 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_types.h"

static int		add_arg(t_ftlist *lst, long long int value)
{
	t_lst_elem	*new;

	if (!lst || !(new = malloc(sizeof(t_lst_elem))))
		return (1);
	new->value = value;
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

static int		rm_last(t_ftlist *lst)
{
	t_lst_elem	*rm;

	if (!lst)
		return (1);
	if (!lst->tail || !lst->head || !lst->size)
		return (0);
	rm = lst->tail;
	lst->tail = rm->prev;
	if (rm == lst->head)
		lst->head = NULL;
	free(rm);
	lst->size--;
	return (0);
}

static int		rm_first(t_ftlist *lst)
{
	t_lst_elem	*rm;

	if (!lst)
		return (1);
	if (!lst->tail || !lst->head || !lst->size)
		return (0);
	rm = lst->head;
	lst->head = rm->next;
	if (rm == lst->tail)
		lst->tail = NULL;
	free(rm);
	lst->size--;
	return (0);
}

void			clear_list(t_ftlist *lst)
{
	while (lst && lst->head && lst->tail && lst->size)
	{
		rm_first(lst);
		rm_last(lst);
	}
}

void			get_arg(t_printf *data, size_t idx)
{
	if (idx == 0 || !data)
		return ;
	while (data->args.size < idx)
	{
		if (add_arg(&data->args, va_arg(data->va_lst, long long int)))
			return ;
	}
}
