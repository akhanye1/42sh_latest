/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:25:35 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/26 23:48:56 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	i;

	if (str == NULL)
		return (NULL);
	temp = (char *)malloc((sizeof(char) * (len)) + 1);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while ((str[start + i] != '\0') && (i < len))
	{
		temp[i] = str[i + start];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
