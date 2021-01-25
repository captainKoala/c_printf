/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:30:16 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:45 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parser(const char *format, va_list argptr)
{
	t_parser_opts	popts;
	t_options		opts;

	ft_popts_init(&popts);
	while (format[popts.i])
	{
		if (!ft_is_format_starts(format, &popts, &opts))
		{
			ft_parser_auxiliary_loop(format, &popts, &opts, argptr);
			popts.i--;
		}
		popts.i++;
	}
	return (popts.full_len);
}

int		ft_printf(const char *format, ...)
{
	va_list		argptr;
	int			full_len;

	va_start(argptr, format);
	full_len = ft_parser(format, argptr);
	va_end(argptr);
	return (full_len);
}
