/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <fcntl.h>

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

int	read_arguments(char *arg)
{
	ft_printf("Lecture des arguments: [%s]\n", arg);

	int	fd;

	if ((fd = open(arg, 'r')) == -1)
		return (print_no_file(arg));
	ft_printf("Open file [%s]: ok\n", arg);
	return (0);
}