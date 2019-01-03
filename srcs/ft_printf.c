/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:56:12 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/03 19:03:13 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include "ft_printf.h"
#include "ft_types.h"
#include "libft.h"

int				ft_printf(const char *format, ...)
{
	int			size;
	t_printf	data;

	if (!format)
		return (ERROR);
	data.buf = NULL;
	ft_bzero(&data, sizeof(data));
	data.err = errno;
	data.use_chain_format = MAYBE;
	va_start(data.va_lst, format);
	if ((size = get_non_arg(format, &data)) < 0)
		return (ft_freturn(data.buf, ERROR));
	while (*(format += size))
	{
		if ((size = parse_conversion(&format, &data)) < 0)
			return (ft_freturn(data.buf, ERROR));
		if ((size = get_non_arg(format, &data)) < 0)
			return (ft_freturn(data.buf, ERROR));
	}
	va_end(data.va_lst);
	clear_list(&data.args);
	return (ft_freturn(data.buf, write(1, data.buf, ft_strlen(data.buf))));
}
