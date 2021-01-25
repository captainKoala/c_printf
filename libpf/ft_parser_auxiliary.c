/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:30:40 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:46 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_parse_num(const char *format, t_parser_opts *popts,
						t_options *opts, int has_pres)
{
	int	num;

	num = 0;
	while (ft_isdigit(format[popts->i]))
	{
		num = 10 * num + format[popts->i] - 48;
		(popts->i)++;
	}
	if (has_pres)
		opts->precision = num;
	else
		opts->width = num;
	(popts->i)--;
}

void	ft_parse_asterisk(va_list argptr, int has_pres, t_options *opts)
{
	int val;

	val = va_arg(argptr, int);
	if (has_pres)
	{
		if (val < 0)
			opts->precision = -1;
		else
			opts->precision = val;
	}
	else if (val < 0)
	{
		opts->flag_minus = 1;
		opts->width = -val;
	}
	else
		opts->width = val;
}

int		start_conversion(t_parser_opts *popts, t_options *opts, va_list argptr)
{
	int	full_len;

	(popts->is_format_str) = 0;
	(popts->has_pres) = 0;
	if (opts->arg_type == 'c')
		full_len = ft_conversion_c(va_arg(argptr, int), opts);
	if (opts->arg_type == 's')
		full_len = ft_conversion_s(va_arg(argptr, char *), opts);
	if (opts->arg_type == 'd' || opts->arg_type == 'i')
		full_len = ft_conversion_d(va_arg(argptr, int), opts);
	if (opts->arg_type == 'x' || opts->arg_type == 'X' ||
		opts->arg_type == 'u')
		full_len = ft_conversion_d(va_arg(argptr, unsigned), opts);
	if (opts->arg_type == 'p')
		full_len = ft_conversion_p(
				(size_t)va_arg(argptr, void*), opts);
	if (opts->arg_type == '%')
		full_len = ft_conversion_perc(opts);
	return (full_len);
}

int		ft_is_char_in_str(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_parse_flags(char flag, int has_pres, t_options *opts)
{
	if (flag == '-')
		opts->flag_minus = 1;
	else if (flag == '+')
		opts->flag_plus = 1;
	else if (flag == ' ')
		opts->flag_space = 1;
	else if (flag == '0' && !has_pres)
		opts->flag_zero = 1;
	else if (flag == '#')
		opts->flag_sharp = 1;
}
