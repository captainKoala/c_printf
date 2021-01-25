/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:30:16 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:45 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include "stdlib.h"

typedef struct	s_options
{
	int		flag_minus;
	int		flag_zero;
	int		flag_plus;
	int		flag_space;
	int		flag_sharp;
	int		sign;
	char	sign_char;
	int		width;
	int		precision;
	char	arg_type;
}				t_options;
typedef struct	s_print_lens
{
	int		len;
	int		flen;
	int		nulls;
	int		spaces;
}				t_print_lens;
typedef struct	s_parser_opts
{
	int			is_format_str;
	int			has_pres;
	int			full_len;
	int			i;
}				t_parser_opts;
size_t			ft_strlen(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
void			ft_putnbr_fd(int n, int fd);
unsigned		ft_putnbr_with_base_fd(long num, int base,
										char *charset, int fd);
void			ft_print_n_chars(char c, long n);
int				ft_conversion_c(char c, t_options *opts);
int				ft_conversion_s(char *s, t_options *opts);
unsigned		count_signs_in_number(long num, unsigned base);
int				ft_get_base(t_options *opts);
char			*ft_get_charset(t_options *opts);
int				ft_conversion_d(long long d, t_options *opts);
int				ft_conversion_p(size_t pointer, t_options *opts);
int				ft_conversion_perc(t_options *opts);
int				ft_abs(int num);
unsigned		count_signs_in_number(long num, unsigned base);
int				ft_get_base(t_options *opts);
char			*ft_get_charset(t_options *opts);
void			ft_parse_num(const char *format, t_parser_opts *popts,
						t_options *opts, int has_pres);
void			ft_parse_asterisk(va_list argptr, int has_pres,
						t_options *opts);
int				start_conversion(t_parser_opts *popts, t_options *opts,
						va_list argptr);
int				ft_is_char_in_str(char c, char *str);
void			ft_parse_flags(char flag, int has_pres, t_options *opts);
void			ft_parser_auxiliary_loop(const char *format,
					t_parser_opts *popts, t_options *opts, va_list argptr);
int				ft_is_format_starts(const char *format, t_parser_opts *popts,
									t_options *opts);
void			ft_popts_init(t_parser_opts *popts);
void			ft_opts_init(t_options *opts);
char			get_arg_type(char c);
#endif
