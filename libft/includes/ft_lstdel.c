/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 07:55:51 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/09 14:15:43 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = (*alst);
	while (tmp)
	{
		(*alst) = tmp;
		del(tmp->content, tmp->content_size);
		free((*alst));
		(*alst) = NULL;
		tmp = tmp->next;
	}
}
