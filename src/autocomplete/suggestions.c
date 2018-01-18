/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suggestions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 10:17:37 by akhanye           #+#    #+#             */
/*   Updated: 2017/09/22 14:40:06 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void		autofill_word(char *original, char *suggestion)
{
	int	i;
	int	n;
	int	max;

	i = ft_strlen(original);
	while (--i > 0 && (original[i] != ' ' && original[i] != '/'))
		;
	if (original[i] == ' ' || original[i] == '/')
		i++;
	n = 0;
	while (original[i++] == suggestion[n++])
		;
	ft_strcat(original, suggestion + (n - 1));
	max = (MAXWDIR - 20) - ft_strlen(original);
	ft_bzero(original + ft_strlen(original), max);
}

static char	count_suggestions(char words[42][MAXWDIR])
{
	int	i;

	i = -1;
	while (ft_strlen(words[++i]))
		;
	return (i - 1);
}

static void	print_sugg(int index, char *keyd_word,
				char words[42][MAXWDIR], t_con *env)
{
	index = 0;
	autofill_word(keyd_word, words[index]);
	if (count_suggestions(words))
	{
		show_usr_suggestions(words, env);
		ft_putstr("$> ");
		ft_putstr(keyd_word);
	}
	else
		clear_line(keyd_word, env);
	env->index = ft_strlen(keyd_word);
	end_key(&(env->index), ft_strlen(keyd_word), env);
}

static void	next_sugg(char words[42][MAXWDIR],
				char *keyd_word, t_con *env, int *index)
{
	*index = (ft_strlen(words[*index + 1])) ? *index + 1 : 0;
	autofill_word(keyd_word, words[*index]);
	show_suggestion(keyd_word, env);
}

void		suggestions(char *word, char type, t_con *env, int *n)
{
	static char		*keyd_word = NULL;
	static char		words[42][MAXWDIR];
	static int		i = 0;
	static int		index = 0;

	if (type == RESET)
	{
		ft_bzero(words, sizeof(words));
		return ;
	}
	if (type == STORE)
	{
		keyd_word = word;
		return ;
	}
	if (i++ == 0)
		ft_bzero(words, sizeof(words));
	if (type == ADD)
		ft_strcpy(words[++(*n)], word);
	if (type == PRINT && keyd_word)
		print_sugg(index, keyd_word, words, env);
	if (type == NEXT)
		next_sugg(words, keyd_word, env, &index);
}
