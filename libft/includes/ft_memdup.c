/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:25:35 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/17 14:49:27 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned char	*ft_memdup(const unsigned char *mem, size_t sz)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)malloc(sizeof(unsigned char) * sz);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < sz)
	{
		temp[i] = mem[i];
		i++;
	}
	return (temp);
}
