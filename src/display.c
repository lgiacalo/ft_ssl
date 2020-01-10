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

void	print_hash(unsigned int state[4])
{
	ft_printf("%.8x%.8x%.8x%.8x", state[0], \
		state[1], state[2], state[3]);
}

void	display_hash(char *name)
{
	t_ssl	*ssl;
	char	c;

	ssl = getssl();
	c = (ssl->opt & OPT_S) ? '"' : 0;
	if (ssl->opt & OPT_Q)
		print_hash(ssl->state);
	else if ((ssl->opt & OPT_P) || (ssl->opt & OPT_R))
	{
		print_hash(ssl->state);
		if (!(ssl->opt & OPT_P))
			ft_printf(" %c%s%c", c, name, c);
	}
	else
	{
		ft_printf("MD5 (%c%s%c) = ", c, name, c);
		print_hash(ssl->state);
	}
	ft_printf("\n");
	clean_ssl();
}