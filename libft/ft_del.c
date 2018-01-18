/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbotho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 18:26:27 by nmbotho           #+#    #+#             */
/*   Updated: 2017/10/01 18:26:31 by nmbotho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *content, size_t content_size)
{
	free(content);
	content_size = content_size * 2;
	content_size = 0;
	content = NULL;
}
