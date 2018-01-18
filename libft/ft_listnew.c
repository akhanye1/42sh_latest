/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:35:53 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/30 13:40:33 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_listnew(int size)
{
	char **ret;

	ret = (char**)malloc(sizeof(ret) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (size != -1)
	{
		ret[size] = 0;
		size--;
	}
	return (ret);
}
