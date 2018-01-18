/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:33:45 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/04 10:22:37 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	*mem2;
	unsigned char	ch;
	size_t			i;

	i = 0;
	mem = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	ch = (unsigned char)c;
	while (i < n)
	{
		mem[i] = mem2[i];
		if (mem2[i] == ch)
			return (mem + (i + 1));
		i++;
	}
	return (NULL);
}
