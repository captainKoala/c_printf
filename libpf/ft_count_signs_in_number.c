/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_signs_in_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwyn <rgwyn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:30:46 by rgwyn             #+#    #+#             */
/*   Updated: 2021/01/23 12:31:47 by rgwyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	count_signs_in_number(long num, unsigned base)
{
	unsigned	counter;

	if (num == 0)
		return (1);
	counter = 0;
	if (num < 0)
	{
		num = -num;
		counter++;
	}
	while (num > 0)
	{
		num /= base;
		counter++;
	}
	return (counter);
}
