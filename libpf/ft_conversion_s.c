/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:30:52 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:47 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conversion_s(char *s, t_options *opts)
{
	t_print_lens	lens;
	int				i;

	if (!s)
		s = "(null)";
	lens.len = ft_strlen(s);
	if (opts->precision != -1 && opts->precision < lens.len)
		lens.len = opts->precision;
	lens.nulls = opts->flag_zero && opts->width > lens.len ?
		opts->width - lens.len : 0;
	lens.spaces = lens.len + lens.nulls < opts->width ?
		opts->width - lens.len - lens.nulls : 0;
	if (lens.spaces && !opts->flag_minus)
		ft_print_n_chars(' ', lens.spaces);
	if (lens.nulls)
		ft_print_n_chars('0', lens.nulls);
	i = 0;
	while (i < lens.len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	if (lens.spaces && opts->flag_minus)
		ft_print_n_chars(' ', lens.spaces);
	return (lens.len + lens.spaces);
}
