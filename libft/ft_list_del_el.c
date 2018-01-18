/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_el.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:19:28 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/13 15:45:28 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_del_el(char **list, char *el)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (list[i])
	{
		if (ft_strcmp(list[i], el) == 0)
		{
			f = 1;
			free(list[i]);
			list[i] = NULL;
		}
		if (f)
		{
			list[i] = list[i + 1];
		}
		i++;
	}
	if (f)
	{
		free(list[i]);
		list[i] = NULL;
	}
	return (f);
}
