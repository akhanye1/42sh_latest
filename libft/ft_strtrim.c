/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:26:47 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/28 14:15:50 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		x;
	char	*ret;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	x = ft_strlen(s) - 1;
	while (s[x] == ' ' || s[x] == '\t' || s[x] == '\n')
		x--;
	ret = ft_strsub(s, i, (x - i) + 1);
	return (ret);
}
