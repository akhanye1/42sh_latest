/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:23:13 by akhanye           #+#    #+#             */
/*   Updated: 2018/01/17 10:27:18 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void		free_2d_array(void **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}