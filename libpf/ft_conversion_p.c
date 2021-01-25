/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:30:58 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:48 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_conversion_p(size_t pointer, t_options *opts)
{
	int len;
	int spaces;
	int nulls;

	opts->arg_type = 'p';
	len = count_signs_in_number(pointer, 16);
	if (pointer == 0 && opts->precision == 0)
		len = 0;
	nulls = opts->precision > len ? opts->precision - len : 0;
	spaces = opts->width > len + nulls + 2 ? opts->width - nulls - len - 2 : 0;
	if (!opts->flag_minus && spaces)
		ft_print_n_chars(' ', spaces);
	ft_putstr_fd("0x", 1);
	if (nulls)
		ft_print_n_chars('0', nulls);
	if (len)
		ft_putnbr_with_base_fd(pointer, 16, "0123456789abcdef", 1);
	if (opts->flag_minus && spaces)
		ft_print_n_chars(' ', spaces);
	return (len + 2 + spaces + nulls);
}
