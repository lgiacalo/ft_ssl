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

void	read_stdin(char *buff)
{
	char	*tmp;
	size_t	size;
	size_t	size_tt;

	size_tt = 0;
	tmp = (char *)buff;
	while ((size = read(0, tmp, SIZE_READ - size_tt)) >= 0)
	{
		size_tt += size;
		if (size_tt == SIZE_READ || !size)
		{
			write(1, buff, size_tt);
			gestion_block(buff, size_tt, (!size) ? 63 : 0);
			if (!size)
			{
				gestion_last_block(buff, size_tt);
				break ;
			}
			ft_bzero(buff, SIZE_READ);
			tmp = (char *)buff;
			size_tt = 0;
		}
		else
			tmp += size;
	}
}

int		gestion_stdin(void)
{
	t_ssl	*ssl;
	char	buff[SIZE_READ];

	ssl = getssl();
	if (ssl->opt & OPT_PP)
		return (gestion_string(""));
	ssl->opt |= (1 << 4);
	ssl->opt |= (1 << 0);
	read_stdin(buff);
	display_hash(NULL);
	return (0);
}

int		record_commands(char *cmd)
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

/*
**	si -pp alors entre standard + ""
*/

int		record_option(char *str)
{
	int	i;
	int	ind;

	i = 0;
	while (str && str[++i])
	{
		if ((ind = ft_chrstr_ind(str[i], OPT_STR)) < 0)
			return (print_illegal_option(str[i]));
		getssl()->opt |= (1 << ind);
		if (str[i] == 'p')
			gestion_stdin();
		else if (str[i] == 's')
			return (read_string_option(str + i));
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
