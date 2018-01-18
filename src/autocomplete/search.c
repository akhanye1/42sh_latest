/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 18:20:17 by akhanye           #+#    #+#             */
/*   Updated: 2017/11/07 09:33:43 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

static char		show_bin_sug(char **str, t_tri **head, t_con *env, int n)
{
	t_tri		*temp;
	t_temp		local;
	int			len;
	char		sugest[MAXWDIR];
	t_tri		*mem[2000];

	temp = (*head);
	ft_strcpy(sugest, (*str));
	ft_bzero(mem, sizeof(mem));
	len = ft_strlen(sugest);
	mem[len] = temp;
	local.suggest = sugest;
	local.n = n;
	local.con = env;
	find_suggestion(mem, &temp, &len, &local);
	return (TRUE);
}

static char		search_binary(char *trim, t_tri **head, t_con *env)
{
	int			i;
	int			ind;
	t_tri		*temp;

	i = -1;
	temp = (*head);
	while (trim[++i])
	{
		if ((ind = get_tri_index(trim[i])) == -1)
		{
			free(trim);
			return (FALSE);
		}
		if (!(temp->letter[ind]))
		{
			free(trim);
			return (FALSE);
		}
		else
			temp = temp->letter[ind];
	}
	show_bin_sug(&trim, &temp, env, -1);
	free(trim);
	return (TRUE);
}

char			smart_suggest(char **str, t_con *env, char **mem, int *x)
{
	ft_strcpy((*str), (*mem));
	suggestions((*str), STORE, env, x);
	suggestions(NULL, NEXT, env, x);
	return (TRUE);
}

char			search(char **str, t_tri **head, t_con *env)
{
	static char	*mem = NULL;
	int			x;
	char		*trim;

	x = 0;
	if (!str)
	{
		if (mem)
			free(mem);
		mem = NULL;
		suggestions(NULL, RESET, NULL, NULL);
		return (TRUE);
	}
	if (!mem)
		mem = ft_strdup((*str));
	else
		return (smart_suggest(str, env, &mem, &x));
	suggestions((*str), STORE, env, &x);
	trim = ft_strtrim((*str));
	if (ft_strchr(trim, ' ') || ft_strchr(trim, '/') || ft_strchr(trim, '>') ||
			ft_strchr(trim, '<'))
		return (search_files(trim, env));
	else
		return (search_binary(trim, head, env));
}
