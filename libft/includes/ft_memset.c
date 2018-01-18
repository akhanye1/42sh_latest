/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:29:43 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/03 15:36:20 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sh;
	size_t			i;

	i = 0;
	str = (unsigned char*)s;
	sh = (unsigned char)c;
	while (i < n)
	{
		str[i] = sh;
		i++;
	}
	return (str);
}
