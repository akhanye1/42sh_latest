/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 17:16:34 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/29 13:32:52 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_listcat(char **list, char *str)
{
	char	**ret;
	int		len;
	int		i;

	if (list == NULL || str == NULL)
		return (NULL);
	len = countlist(list);
	ret = (char **)malloc(sizeof(ret) * (len + 2));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (list[i])
	{
		ret[i] = ft_strnew(ft_strlen(list[i]));
		ft_strcpy(ret[i], list[i]);
		i++;
	}
	ret[i] = ft_strnew(ft_strlen(str));
	ft_strcpy(ret[i], str);
	ret[i + 1] = 0;
	return (ret);
}
