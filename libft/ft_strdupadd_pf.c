/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 05:57:48 by mkgosise          #+#    #+#             */
/*   Updated: 2017/06/28 14:40:42 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdupadd(const char *str)
{
	char *tmp;
	char *ret;

	tmp = ft_strnew(1);
	tmp[0] = '?';
	ret = ft_strjoin(str, tmp);
	free(tmp);
	return (ret);
}
