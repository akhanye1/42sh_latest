/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:41:16 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/10 21:22:09 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr(int num)
{
	if (num < 0)
	{
		if (num == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		else
		{
			ft_putchar('-');
			num = -1 * num;
		}
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		ft_putchar('0' + num);
	}
}
