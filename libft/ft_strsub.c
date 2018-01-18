/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:39:36 by mkgosise          #+#    #+#             */
/*   Updated: 2017/06/11 12:37:44 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(char const *s, int x, int l)
{
	int i;

	i = 0;
	while (s[x] && l > 0)
	{
		i++;
		x++;
		l--;
	}
	return (i);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	size_t	l;
	char	*str;

	if (!ft_isascii(s[start]) || (int)len < 0 || s == NULL || (int)start < 0)
		return (NULL);
	l = getlen(s, start, len);
	str = (char*)ft_memalloc(l + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[start] && (int)len > 0)
	{
		str[i] = s[start];
		start++;
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
