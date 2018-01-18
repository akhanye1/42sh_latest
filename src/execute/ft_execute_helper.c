/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:09:59 by mkgosise          #+#    #+#             */
/*   Updated: 2017/12/18 14:11:57 by skgatle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_42sh.h"

int		ft_store_fd(int *stdin, int *stdout, int *stderr)
{
	if ((*stdin = dup(STDIN_FILENO)) == -1 ||
			(*stdout = dup(STDOUT_FILENO)) == -1 ||
			(*stderr = dup(STDERR_FILENO)) == -1)
		return (-1);
	return (1);
}

int		ft_restore_fd(int stdin, int stdout, int stderr)
{
	if (dup2(stdin, STDIN_FILENO) == -1 ||
			dup2(stdout, STDOUT_FILENO) == -1 ||
			dup2(stderr, STDERR_FILENO) == -1)
		return (-1);
	return (1);
}
