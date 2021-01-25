/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:33:29 by rgwyn             #+#    #+#             */
/*   Updated: 2020/11/08 20:20:42 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	ft_putnbr_with_base_fd(long num, int base, char *charset, int fd)
{
	unsigned len;

	len = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num < base)
	{
		ft_putchar_fd(charset[num], fd);
		len = 1;
	}
	else
	{
		len += ft_putnbr_with_base_fd(num / base, base, charset, fd);
		ft_putchar_fd(charset[num % base], fd);
	}
	return (len);
}
