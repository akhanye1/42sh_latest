/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:02:21 by mkgosise          #+#    #+#             */
/*   Updated: 2017/06/30 04:57:15 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	ret = ft_memalloc(size + 1);
	if (ret == NULL)
		return (NULL);
	ft_bzero((void*)ret, (size_t)size);
	return (ret);
}
