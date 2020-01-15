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
#include "ft_sha.h"

void	print_hash(unsigned int state[], int ind)
{
	int	i;

	i = -1;
	while (++i < ind)
		ft_printf("%.8x", state[i]);
}

void	display_hash(char *name)
{
	t_ssl	*ssl;
	char	c;

	ssl = getssl();
	c = (ssl->opt & OPT_S) ? '"' : 0;
	if (ssl->opt & OPT_Q)
		print_hash(ssl->state, 4);
	else if ((ssl->opt & OPT_P) || (ssl->opt & OPT_R))
	{
		print_hash(ssl->state, 4);
		if (!(ssl->opt & OPT_P))
			ft_printf(" %c%s%c", c, name, c);
	}
	else
	{
		ft_printf("MD5 (%c%s%c) = ", c, name, c);
		print_hash(ssl->state, 4);
	}
	ft_printf("\n");
	clean_ssl();
}

void	display_hash256(char *name)
{
	t_sha	*sha;
	char	c;

	sha = getsha();
	c = (sha->opt & OPT_S) ? '"' : 0;
	if (sha->opt & OPT_Q)
		print_hash(sha->state, 8);
	else if ((sha->opt & OPT_P) || (sha->opt & OPT_R))
	{
		print_hash(sha->state, 8);
		if (!(sha->opt & OPT_P))
			ft_printf(" %c%s%c", c, name, c);
	}
	else
	{
		ft_printf("SHA256(%c%s%c)= ", c, name, c);
		print_hash(sha->state, 8);
	}
	ft_printf("\n");
	clean_sha();
}