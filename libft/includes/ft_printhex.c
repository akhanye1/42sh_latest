/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:05:35 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/03 15:37:09 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printhex(unsigned char num)
{
	char hstr[16];

	ft_strcpy(hstr, "0123456789abcdef");
	if (num == 0)
	{
		ft_putchar('0');
	}
	else if (num < 16)
		ft_putchar(hstr[num]);
	else
	{
		ft_printhex(num % 16);
		ft_printhex(num / 16);
	}
}
