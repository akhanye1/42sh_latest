/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:13:26 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/03 15:45:07 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	while ((haystack[i] != '\0') && (i < len))
	{
		n = 0;
		while ((needle[n] != '\0') && (needle[n] == haystack[i + n]))
		{
			n++;
		}
		if ((needle[n] == '\0') && ((i + n) <= len))
			return (char*)(haystack + i);
		i++;
	}
	return (NULL);
}
