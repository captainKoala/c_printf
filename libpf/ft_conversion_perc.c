/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_perc_lens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:42:52 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 14:57:47 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_conversion_perc(t_options *opts)
{
	int		fills;
	char	fill_char;

	if (opts->width < 0)
		return (0);
	fills = opts->width > 1 ? opts->width - 1 : 0;
	if (fills)
		fill_char = opts->flag_zero && !opts->flag_minus ? '0' : ' ';
	if (fills && !opts->flag_minus)
		ft_print_n_chars(fill_char, fills);
	ft_putchar_fd('%', 1);
	if (fills && opts->flag_minus)
		ft_print_n_chars(fill_char, fills);
	return (fills + 1);
}
