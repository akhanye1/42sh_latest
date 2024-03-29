/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:25:35 by nmbotho           #+#    #+#             */
/*   Updated: 2017/10/01 18:25:40 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count2d(void **array)
{
	int i;

	i = 0;
	if (array)
		while (array[i])
			i++;
	return (i);
}
