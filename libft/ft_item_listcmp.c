/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item_listcmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 16:16:57 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/29 14:58:04 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_item_listcmp(char **list, char *item)
{
	int i;

	i = 0;
	while (list[i])
	{
		if (ft_strncmp(list[i], item, ft_strlen(item)) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}
