/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printallhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:10:50 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/08 14:25:41 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printallhex(unsigned char *bytes, size_t sz)
{
	size_t i;

	if (bytes == NULL)
		return ;
	i = 0;
	while (i < sz)
	{
		if ((i > 0) && (i % 2 == 0))
			ft_putchar(' ');
		ft_printhex(bytes[i]);
		i++;
	}
}
