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
	if (ind < NB_HASH)
	{
		ssl->f = ind;
		ft_strupcase(cmd);
		return (0);
	}
	ssl->cmd = NULL;
	return (1);
}


int		ssl(int argc, char **argv)
{
	init_ssl();
	if (record_commands(argv[1]))
		return (print_usage_commands(argv[1]));
	g_hash[getssl()->f].func(argv, argc);
	return (0);
}

int		ft_quit(char *str)
{
	if (ft_strncmp(str, "quit", 4))
		return (0);
	return (1);
}

int		gestion_interactif(char *buf)
{
	char	**split;
	char	*tmp;
	char	len;

	if (!*buf)
		return (0);
	tmp = ft_strjoin("./ft_ssl ", buf);
	split = ft_strsplit(tmp, ' ');
	free(tmp);
	len = tab_len(split);
	if (len == 1)
		return (0);
	if (ft_quit(split[1]))
	{
		free_tab(&split);
		return (1);
	}
	ssl(len, split);
	free_tab(&split);
	return (0);
}

int		main(int argc, char **argv)
{
	char	*buf;
	int		ret;

	if (argc == 1)
	{
		ft_printf("ft_ssl> ");
		while ((ret = get_next_line(0, &buf)) > 0)
		{
			if (gestion_interactif(buf))
				break ;
			ft_printf("ft_ssl> ");
			free(buf);
		}
	}
	else
		ssl(argc, argv);
	ft_printf("nb=[%d]\n", getssl()->nb);
	return (getssl()->nb ? 1 : 0);
}
