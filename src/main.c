/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		record_commands(char *cmd)
{
	t_ssl	*ssl;
	char	*s;
	int		ind;

	ssl = getssl();
	ssl->cmd = cmd;
	s = ft_strlowcase(cmd);
	ind = 0;
	while (g_hash[ind].func && strcmp(s, g_hash[ind].name))
		ind++;
	ft_printf("ind = [%d]\n", ind);
	if (ind < NB_HASH)
	{
		ssl->f = ind;
		return (0);
	}
	ssl->cmd = NULL;
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (print_usage());
	init_ssl();
	if (record_commands(argv[1]))
		return (print_usage_commands(argv[1]));
	g_hash[getssl()->f].func(argv, argc);
	return (0);
}
