/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:04:29 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/08 14:39:09 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_locchr(char *str, char c)
{
	char *ret;

	if (str == NULL)
		return (0);
	ret = ft_strchr(str, c);
	if (ret)
		return (1);
	else
		return (0);
}
