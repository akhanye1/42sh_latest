/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:21:53 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/04 17:06:05 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char*)malloc(size);
	i = 0;
	if (temp == NULL)
		return (NULL);
	while (i < size)
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
}
