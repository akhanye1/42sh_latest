/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:59:50 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/25 06:29:36 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t di;
	size_t max;
	size_t c;

	di = ft_strlen(dest);
	if (n > di)
	{
		i = 0;
		c = di;
		max = n - (di + 1);
		while ((src[i] != '\0') && (i < max))
		{
			dest[c] = src[i];
			i++;
			c++;
		}
		dest[c] = '\0';
		di += ft_strlen(src);
	}
	else
		di = ft_strlen(src) + n;
	return (di);
}
