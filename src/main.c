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

int		main(int argc, char **argv)
{
	if (argc == 1)
		return (print_usage());
	init_ssl();
	if (record_commands(argv[1]))
		return (print_usage_commands(argv[1]));
	if (argc == 2)
		gestion_stdin();
	else
		record(argv, argc);
	return (0);
}
