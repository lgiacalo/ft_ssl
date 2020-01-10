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


void	read_stdin(void)
{
	ft_printf("Read sur l'entree standard !\n");
}


int	record_commands(char *cmd)
{
	t_ssl	*ssl;

	ssl = getssl();
	ssl->cmd = cmd;
	if (!strcmp(CMD_MD5, cmd))
		return (0);
	else if (!strcmp(CMD_SHA256, cmd))
		return (0);
	ssl->cmd = NULL;
	return (1);
}


int	record_option(char *str)
{
	int	i;
	int	ind;

	i = 0;
	while (str && str[++i])
	{
		if ((ind = ft_chrstr_ind(str[i], OPT_STR)) < 0)
			return (print_illegal_option(str[i]));
		if (!(getssl()->opt & OPT_P) && str[i] == 'p')
			read_stdin();
		else if (str[i] == 's')
			return (read_string_option(str + i));
		getssl()->opt |= (1 << ind);

	}
	return (0);
}

void	record(char **argv, int argc)
{
	int	i; 
	int	opt;

	i = 2; 
	opt = 1;
	while (i < argc)
	{
		if (opt && argv[i][0] == '-')
		{
			if (record_option(argv[i]) == -1)
				read_string(argv[++i]);
		}
		else
		{
			opt = 0;
			read_arguments(argv[i]);
		}
		i++;
	}
}