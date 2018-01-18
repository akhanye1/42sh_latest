/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 20:02:20 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/27 00:37:07 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;
	size_t	i;

	size++;
	temp = (char *)malloc(sizeof(char) * size);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		temp[i++] = '\0';
	return (temp);
}
