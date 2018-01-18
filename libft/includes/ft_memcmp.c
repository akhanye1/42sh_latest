/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:51:25 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/03 15:35:11 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	i = 0;
	b1 = (unsigned char*)s1;
	b2 = (unsigned char*)s2;
	while ((i < n) && (b1[i] == b2[i]))
	{
		i++;
	}
	if (i < n)
		return (b1[i] - b2[i]);
	return (0);
}
