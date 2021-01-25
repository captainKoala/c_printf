/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:31:12 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:50 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_print_n_chars(char c, long n)
{
	while (n > 0)
	{
		ft_putchar_fd(c, 1);
		n--;
	}
}

int			ft_conversion_c(char c, t_options *opts)
{
	int len;

	len = 1;
	if (opts->width > 1)
		len = opts->width;
	if (len > 1 && !opts->flag_minus)
		ft_print_n_chars(' ', len - 1);
	ft_putchar_fd(c, 1);
	if (len > 1 && opts->flag_minus)
		ft_print_n_chars(' ', len - 1);
	return (len);
}
