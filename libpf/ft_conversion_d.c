/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:31:03 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:49 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_set_sign(long long *d, t_options *opts)
{
	if (*d < 0)
	{
		opts->sign = -1;
		opts->sign_char = '-';
		*d = -(*d);
	}
	else if (opts->flag_plus)
	{
		opts->sign = 1;
		opts->sign_char = '+';
	}
	else if (opts->flag_space)
	{
		opts->sign = 1;
		opts->sign_char = ' ';
	}
	if (opts->flag_minus)
		opts->flag_zero = 0;
}

char		*ft_is_x_with_sharp(long long d, t_options *opts)
{
	if (opts->flag_sharp && d != 0)
	{
		if (opts->arg_type == 'x')
			return ("0x");
		else if (opts->arg_type == 'X')
			return ("0X");
	}
	return (0);
}

void		ft_calc_lens_for_d(t_print_lens *lens, long long d, t_options *opts)
{
	int		xlen;

	lens->len = count_signs_in_number(d, ft_get_base(opts));
	xlen = ft_is_x_with_sharp(d, opts) ? 2 : 0;
	if (opts->precision == 0 && d == 0)
		lens->len = 0;
	lens->nulls = lens->len < opts->precision ? opts->precision - lens->len : 0;
	if (opts->width > lens->len + xlen + lens->nulls + ft_abs(opts->sign) &&
		opts->flag_zero && opts->precision == -1)
		lens->nulls += opts->width - lens->nulls -
				lens->len - xlen - ft_abs(opts->sign);
	lens->spaces = (opts->width > ft_abs(opts->sign) + lens->nulls + lens->len +
			xlen) ? (opts->width - ft_abs(opts->sign) -
					lens->len - xlen - lens->nulls) : 0;
	lens->flen = lens->spaces + ft_abs(opts->sign) +
			lens->nulls + lens->len + xlen;
}

int			ft_conversion_d(long long d, t_options *opts)
{
	t_print_lens lens;

	ft_set_sign(&d, opts);
	ft_calc_lens_for_d(&lens, d, opts);
	if (!opts->flag_minus)
		ft_print_n_chars(' ', lens.spaces);
	if (opts->sign)
		ft_putchar_fd(opts->sign_char, 1);
	ft_putstr_fd(ft_is_x_with_sharp(d, opts), 1);
	if (lens.nulls)
		ft_print_n_chars('0', lens.nulls);
	if (lens.len)
		ft_putnbr_with_base_fd(d, ft_get_base(opts), ft_get_charset(opts), 1);
	if (opts->flag_minus)
		ft_print_n_chars(' ', lens.spaces);
	return (lens.flen);
}
