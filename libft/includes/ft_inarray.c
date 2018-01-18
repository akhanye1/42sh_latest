/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 13:45:21 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/27 12:55:19 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_inarray(char *search, char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (ft_strcmp(search, array[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
