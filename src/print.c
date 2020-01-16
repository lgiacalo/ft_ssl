/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	print_no_file(char *str)
{
	ft_printf("ft_ssl: %s: No such file or directory\n", str);
	getssl()->ret = 1;
	return (0);
}

int	print_requires_args(char opt)
{
	ft_printf("ft_ssl: option requires an argument -- %c\n", opt);
	print_usage();
	getssl()->ret = 1;
	return (1);
}

int	print_illegal_option(char opt)
{
	ft_printf("ft_ssl: illegal option -- %c\n", opt);
	print_usage();
	getssl()->ret = 1;
	return (1);
}

int	print_usage(void)
{
	ft_printf("Usage: ft_ssl commands [-pqr] [-s string] [files ...]\n");
	return (1);
}

int	print_usage_commands(char *cmd)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", cmd);
	ft_printf("\nStandard commands:\n\n");
	ft_printf("Message Digest commands:\n");
	ft_printf("md5\nsha224\nsha256\nsha384\nsha512\n\n");
	ft_printf("Cipher commands:\n");
	return (1);
}
