/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ssl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_sha.h"

t_sha	*getsha(void)
{
	static t_sha	sha;

	return (&sha);
}

void	clean_sha(void)
{
	t_sha	*sha;

	sha = getsha();
	sha->ret = 0;
	if (sha->len_msg == 64)
		sha->version
	? init_state_sha256(sha->state) : init_state_sha224(sha->state);
	if (sha->len_msg == 128)
		sha->version
	? init_state_sha512(sha->statee) : init_state_sha384(sha->statee);
	sha->size = 0;
	sha->size1 = 0;
	sha->opt &= 18;
	ft_bzero(sha->buf, 128);
}

void	init_diff_sha(void)
{
	t_sha	*sha;
	int		num;

	sha = getsha();
	sha->version = 1;
	sha->len_msg = 64;
	sha->len_size = 8;
	if ((num = ft_atoi(sha->cmd + 3)) == 224)
	{
		init_state_sha224(sha->state);
		sha->version = 0;
	}
	else if (num != 256)
	{
		sha->len_msg = 128;
		sha->len_size = 16;
		init_state_sha512(sha->statee);
		if (num == 384)
		{
			sha->version = 0;
			init_state_sha384(sha->statee);
		}
	}
	return ;
}

void	init_sha(void)
{
	t_sha	*sha;

	sha = getsha();
	sha->cmd = getssl()->cmd;
	sha->opt = 0;
	sha->ret = 0;
	sha->f = getssl()->f;
	init_state_sha256(sha->state);
	sha->size = 0;
	sha->size1 = 0;
	ft_bzero(sha->buf, 128);
	init_diff_sha();
}
