/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:43:19 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/09 17:31:11 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_2d(char **arr)
{
	int		i;
	int		x;
	char	*tmp;

	i = 1;
	x = 0;
	while (arr[i])
	{
		if (arr[i][x] < arr[i - 1][x])
		{
			tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
			i = 0;
		}
		i++;
	}
	return (arr);
}

char	**ft_sort_2d_on(char **arr, char **on)
{
	int		i;
	int		x;
	char	*tmp;
	char	*tmp2;

	i = 1;
	x = 0;
	while (arr[i] && on[i])
	{
		if (on[i][x] < on[i - 1][x])
		{
			tmp = arr[i];
			tmp2 = on[i];
			arr[i] = arr[i - 1];
			on[i] = on[i - 1];
			arr[i - 1] = tmp;
			on[i - 1] = tmp2;
			i = 0;
		}
		i++;
	}
	return (arr);
}
