/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_d_auxiliary.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:31:08 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:49 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_get_base(t_options *opts)
{
	if (opts->arg_type == 'd' || opts->arg_type == 'i' || opts->arg_type == 'u')
		return (10);
	if (opts->arg_type == 'x')
		return (16);
	if (opts->arg_type == 'X')
		return (16);
	return (0);
}

char		*ft_get_charset(t_options *opts)
{
	if (opts->arg_type == 'd' || opts->arg_type == 'i' || opts->arg_type == 'u')
		return ("0123456789");
	if (opts->arg_type == 'x')
		return ("0123456789abcdef");
	if (opts->arg_type == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}
