/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:38:34 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/03 15:35:37 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*bytes;
	size_t			i;
	unsigned char	sh;

	i = 0;
	sh = (unsigned char)c;
	bytes = (unsigned char*)s;
	while (i < n)
	{
		if (bytes[i] == sh)
			return (bytes + i);
		i++;
	}
	return (NULL);
}
