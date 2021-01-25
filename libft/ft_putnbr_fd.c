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

void	ft_putnbr_fd(int n, int fd)
{
	long num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num < 10)
		ft_putchar_fd((num + '0'), fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((num % 10 + '0'), fd);
	}
}
