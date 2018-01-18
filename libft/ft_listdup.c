/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:02:58 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/28 11:22:42 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_listdup(char **list)
{
	int		i;
	char	**ret;

	ret = (char**)malloc(sizeof(ret) * (countlist(list) + 1));
	if (ret == NULL)
		return (NULL);
	ret[countlist(list)] = 0;
	i = 0;
	while (list[i])
	{
		ret[i] = ft_strdup(list[i]);
		i++;
	}
	return (ret);
}
