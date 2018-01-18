/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:25:35 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/06 10:04:42 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcpysub(char *dst, const char *src, int start, int len)
{
	int				i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while ((src[i] != '\0') && (i < len))
	{
		dst[i] = src[i + start];
		i++;
	}
	return (dst);
}
