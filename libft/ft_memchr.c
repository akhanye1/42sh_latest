/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 12:39:49 by mkgosise          #+#    #+#             */
/*   Updated: 2017/06/10 07:27:33 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*ret;

	ret = (char*)s;
	i = 0;
	while ((int)n != 0)
	{
		if (ret[i] == c)
			return ((void*)&ret[i]);
		n--;
		i++;
	}
	return (NULL);
}
