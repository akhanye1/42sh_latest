/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:18:37 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/03 17:21:21 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int di;

	i = 0;
	di = (int)ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[di] = src[i];
		i++;
		di++;
	}
	dest[di] = '\0';
	return (dest);
}
