/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:17:49 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/11 16:47:33 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free2d(void **arr)
{
	int i;

	i = countlist((char**)arr);
	if (i == 0 && arr)
		free(arr);
	if (i == 0)
		return ;
	while (i > -1)
	{
		free(arr[i]);
		arr[i] = NULL;
		i--;
	}
	free(arr);
	arr = NULL;
}

void	ft_free2dsafe(void ***arr)
{
	int		i;
	void	**array;

	i = 0;
	array = *arr;
	if (array)
	{
		while (array[i])
		{
			ft_memdel(array + i);
			i++;
		}
	}
	free(*arr);
	*arr = NULL;
}
