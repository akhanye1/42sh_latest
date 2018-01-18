/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 09:53:18 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/17 10:29:14 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

t_andor			*first_node(char *str, int *flag, int *i)
{
	char		*plc;
	t_andor		*top;

	plc = size(str, flag, i);
	top = new_andor(plc);
	free(plc);
	return (top);
}

t_andor			*chaining(char *str, int count)
{
	t_andor		*trav;
	int			flag;
	int			i;
	int			max;
	char		*plc;

	i = 0;
	max = 1;
	trav = first_node(str, &flag, &i);
	trav = new_reset(trav, flag);
	while (str[i])
	{
		plc = size(str, &flag, &i);
		trav = add_reset(trav, plc);
		if (max == count)
		{
			free(plc);
			trav = add_reset(trav, &str[i]);
			break ;
		}
		free(plc);
		trav = flag == 1 ? add_reset(trav, "||") : add_reset(trav, "&&");
		max++;
	}
	return (trav);
}

t_andor			*traversal(t_andor *trav, char *symbol, int *flag)
{
	*flag = 1;
	while (trav && ft_strcmp(trav->comm, symbol) != 0)
		trav = trav->next;
	return (trav);
}

char			**command_list(t_andor *head, char **env)
{
	t_andor		*tv;
	int			val;
	int			flag;

	val = -7;
	tv = head;
	while (tv)
	{
		flag = 0;
		env = run_logical(tv->comm, env, &val);
		if (!tv->next || !tv->next->comm || ft_strlen(tv->next->comm) <= 1)
			break ;
		if (tv->next && ft_strcmp(tv->next->comm, "&&") == 0 &&
		val == 1)
			tv = traversal(tv, "||", &flag);
		else if (tv && ft_strcmp(tv->next->comm, "||") == 0 &&
				val == 0)
			tv = traversal(tv, "&&", &flag);
		if (!tv || !tv->next || !tv->next->next)
			break ;
		if (tv->next && tv->next->next)
			tv = flag == 1 ? tv->next : tv->next->next;
	}
	free_andor(head);
	return (env);
}
