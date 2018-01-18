/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:41:16 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/10 21:22:11 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	if (num < 0)
	{
		if (num == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		else
		{
			ft_putchar_fd('-', fd);
			num = -1 * num;
		}
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
	{
		ft_putchar_fd('0' + num, fd);
	}
}
