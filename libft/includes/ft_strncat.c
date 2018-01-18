/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:59:50 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/30 10:13:46 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t di;

	i = 0;
	di = ft_strlen(dest);
	while ((src[i] != '\0') && (i < n))
	{
		dest[di] = src[i];
		i++;
		di++;
	}
	dest[di] = '\0';
	return (dest);
}
