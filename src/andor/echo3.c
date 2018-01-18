/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:51:54 by angonyam          #+#    #+#             */
/*   Updated: 2018/01/17 10:28:38 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

void			print_out(char *var, char **env)
{
	int			i;
	char		**check;
	int			flag;

	flag = 0;
	i = 0;
	while (env[i])
	{
		check = ft_strsplit(env[i], '=');
		if (ft_strcmp(check[0], var) == 0)
		{
			flag = 1;
			ft_putstr(check[1]);
			free_2d_array((void**)check);
			return ;
		}
		free_2d_array((void**)check);
		i++;
	}
	if (flag == 0)
		ft_putchar(' ');
	ft_putchar(' ');
}

int				env_printing(char *str, char **env)
{
	int			i;
	char		*var;
	char		*to_send;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == ' '
				|| str[i] == '\'' || str[i] == '\"' ||
				str[i] == '\n')
			break ;
		i++;
	}
	var = ft_strsub(str, 0, i);
	to_send = ft_strtrim(var);
	print_out(var, env);
	free(var);
	free(to_send);
	return (i);
}

char			*strip_dots(char *str)
{
	int			i;
	char		*new;
	char		*tester;

	tester = ft_strtrim(str);
	if (!(new = ft_strchr(tester, ' ')))
	{
		free(tester);
		return (NULL);
	}
	free(tester);
	new++;
	i = 0;
	while (new[i])
	{
		if (new[i] == '.')
			new[i] = ' ';
		i++;
	}
	return (ft_strtrim(new));
}

void			echo_d(char *str, char **env, int *val)
{
	char		**cook;
	int			i;

	*val = 1;
	i = 0;
	cook = ft_strsplit(str, '\n');
	while (cook[i])
	{
		if (ft_strchr(cook[i], '$'))
			echo_vpipe(cook[i], env, val);
		else
			ft_putendl(cook[i]);
		i++;
	}
	free_2d_array((void**)cook);
}

void			echo_vpipe(char *str, char **env, int *val)
{
	int			i;
	char		*new;

	*val = 1;
	i = 0;
	new = strip_dots(str);
	if (!new)
		return ;
	while (new[i])
	{
		if (new[i] == '$')
		{
			i++;
			i += env_printing(&new[i], env);
			ft_putchar(' ');
		}
		else
			ft_putchar(new[i]);
		i++;
	}
	ft_putchar('\n');
	free(new);
}
