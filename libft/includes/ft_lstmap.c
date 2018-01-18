/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 08:15:42 by akhanye           #+#    #+#             */
/*   Updated: 2017/06/14 10:23:57 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*temp;
	t_list	*new;

	start = f(lst);
	new = start;
	lst = lst->next;
	while (lst)
	{
		temp = new;
		new = f(lst);
		temp->next = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (start);
}
