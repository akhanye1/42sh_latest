/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:13:26 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/28 09:36:54 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int n;

	i = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		n = 0;
		while ((needle[n] != '\0') && (needle[n] == haystack[i + n]))
		{
			n++;
		}
		if (needle[n] == '\0')
			return (char*)(haystack + i);
		i++;
	}
	return (NULL);
}
