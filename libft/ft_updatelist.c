/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 14:31:27 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/29 13:35:32 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_updatelist(char **arr, char *find, char *src)
{
	int	i;

	if (arr == NULL || find == NULL || src == NULL)
		return (-1);
	i = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], find) == 0)
		{
			free(arr[i]);
			arr[i] = NULL;
			arr[i] = ft_strdup(src);
			return (i + 1);
		}
		i++;
	}
	return (0);
}
