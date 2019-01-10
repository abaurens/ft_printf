/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinteger.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:41:26 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/10 15:45:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UINTEGER_H
# define UINTEGER_H

# include "core/ft_types.h"

/*
**	long.c
*/
char			*long_uinteger(t_printf *const data, t_arg *const arg);
char			*long_long_uinteger(t_printf *const data, t_arg *const arg);

/*
**	short.c
*/
char			*short_uinteger(t_printf *const data, t_arg *const arg);
char			*short_short_uinteger(t_printf *const data, t_arg *const arg);

/*
**	exotic.c
*/
char			*intmax_uinteger(t_printf *const data, t_arg *const arg);
char			*size_uinteger(t_printf *const data, t_arg *const arg);
char			*ssize_uinteger(t_printf *const data, t_arg *const arg);
char			*ptrdiff_uinteger(t_printf *const data, t_arg *const arg);
char			*quad_uinteger(t_printf *const data, t_arg *const arg);
#endif