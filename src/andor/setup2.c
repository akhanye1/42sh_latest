/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:01:21 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/17 10:28:23 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

char			*edit(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}

char			*size(char *segment, int *flag, int *i)
{
	char		*wer;
	int			j;
	char		*ret;

	j = *i;
	while (segment[*i])
	{
		if (segment[*i] == '|' && segment[*i + 1] == '|')
		{
			*flag = 1;
			break ;
		}
		if (segment[*i] == '&' && segment[*i + 1] == '&')
		{
			*flag = 2;
			break ;
		}
		*i = *i + 1;
	}
	wer = ft_strsub(segment, j, *i - j);
	*i += 2;
	ret = ft_strtrim(wer);
	free(wer);
	return (ret);
}

t_andor			*add_reset(t_andor *head, char *plc)
{
	t_andor		*trav;

	trav = head;
	trav = add_andor(head, plc);
	return (head);
}

t_andor			*new_reset(t_andor *head, int flag)
{
	t_andor		*trav;

	trav = head;
	trav = flag == 1 ? add_andor(head, "||") : add_andor(head, "&&");
	return (head);
}
