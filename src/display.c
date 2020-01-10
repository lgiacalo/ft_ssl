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

void	display_hash(char *name)
{
	t_ssl	*ssl;

	// print_ssl();
	ssl = getssl();
	ft_printf("[\"%s\"] : %.8x%.8x%.8x%.8x\n", name, (ssl->state[0]), \
		(ssl->state[1]), (ssl->state[2]), (ssl->state[3]));
	clean_ssl();
}