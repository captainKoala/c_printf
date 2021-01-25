/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:30:16 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:45 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	get_arg_type(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'p' || c == 'u' ||
		c == 'i' || c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

void	ft_opts_init(t_options *opts)
{
	opts->arg_type = 0;
	opts->width = 0;
	opts->precision = -1;
	opts->flag_zero = 0;
	opts->flag_minus = 0;
	opts->flag_plus = 0;
	opts->flag_space = 0;
	opts->flag_sharp = 0;
	opts->sign = 0;
	opts->sign_char = 0;
}

void	ft_popts_init(t_parser_opts *popts)
{
	popts->i = 0;
	popts->has_pres = 0;
	popts->full_len = 0;
	popts->is_format_str = 0;
}

int		ft_is_format_starts(const char *format, t_parser_opts *popts,
							t_options *opts)
{
	if (format[popts->i] == '%' && !(popts->is_format_str))
	{
		(popts->is_format_str) = 1;
		ft_opts_init(opts);
		return (1);
	}
	if (!(popts->is_format_str))
	{
		ft_putchar_fd(format[popts->i], 1);
		(popts->full_len)++;
		return (1);
	}
	return (0);
}

void	ft_parser_auxiliary_loop(const char *format, t_parser_opts *popts,
									t_options *opts, va_list argptr)
{
	while (popts->is_format_str && format[popts->i])
	{
		if (ft_is_char_in_str(format[popts->i], "-+ 0#"))
			ft_parse_flags(format[popts->i], popts->has_pres, opts);
		else if (ft_isdigit(format[popts->i]))
			ft_parse_num(format, popts, opts, popts->has_pres);
		else if (format[popts->i] == '*')
			ft_parse_asterisk(argptr, popts->has_pres, opts);
		else if (format[popts->i] == '.')
		{
			popts->has_pres = 1;
			opts->precision = 0;
		}
		else if ((opts->arg_type = get_arg_type(format[popts->i])))
			popts->full_len += start_conversion(popts, opts, argptr);
		popts->i++;
	}
}
