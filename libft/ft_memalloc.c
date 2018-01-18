/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:38:53 by mkgosise          #+#    #+#             */
/*   Updated: 2017/06/11 05:21:57 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ret;

	ret = (void*)malloc(sizeof(void) * size);
	if (ret == NULL || size == 0)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
