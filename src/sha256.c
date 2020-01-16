/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_sha.h"

static void	init_work_variable256(uint32_t alp[8])
{
	t_sha	*sha;
	int		i;

	sha = getsha();
	i = -1;
	while (++i < 8)
		alp[i] = sha->state[i];
}

static void	compute_inter_hash(uint32_t alp[8])
{
	t_sha	*sha;
	int		i;

	i = -1;
	sha = getsha();
	while (++i < 8)
		sha->state[i] = sha->state[i] + alp[i];
}

void		sha_transform256(uint32_t *block)
{
	uint32_t	w[64];
	uint32_t	alp[8];
	uint32_t	t1;
	uint32_t	t2;
	uint8_t		i;

	message_schedule256(block, w);
	init_work_variable256(alp);
	i = -1;
	while (++i < 64)
	{
		t1 = alp[7] + bsig1(alp[4]) + ch(alp[4], alp[5], alp[6])
		+ g_k[i] + w[i];
		t2 = bsig0(alp[0]) + maj(alp[0], alp[1], alp[2]);
		alp[7] = alp[6];
		alp[6] = alp[5];
		alp[5] = alp[4];
		alp[4] = alp[3] + t1;
		alp[3] = alp[2];
		alp[2] = alp[1];
		alp[1] = alp[0];
		alp[0] = t1 + t2;
	}
	compute_inter_hash(alp);
}

void		gestion_last_block256(char *block, uint64_t size)
{
	t_sha		*sha;
	uint32_t	mod;
	uint32_t	div;

	sha = getsha();
	mod = size % sha->len_msg;
	div = (size / sha->len_msg) * sha->len_msg;
	ft_memcpy(sha->buf, block + div, mod);
	ft_memcpy(sha->buf + mod, g_pad, sha->len_msg - mod);
	if (mod >= (sha->len_msg - sha->len_size))
	{
		sha_transform256((uint32_t *)(&(sha->buf[0])));
		ft_bzero(sha->buf, sha->len_msg);
		ft_memcpy(sha->buf, g_pad + 1, (sha->len_msg - sha->len_size));
	}
	sha->size = reverse64(sha->size);
	ft_memcpy(sha->buf + (sha->len_msg - sha->len_size),
		(unsigned char *)(&(sha->size)), sha->len_size);
	sha_transform256((uint32_t *)(&(sha->buf[0])));
}

void		gestion_block256(char *block, uint64_t size, int add)
{
	t_sha		*sha;
	uint32_t	i;

	sha = getsha();
	sha->size += size * 8;
	i = 0;
	while ((i + ((add) ? sha->len_msg - 1 : 0)) < size)
	{
		sha_transform256((uint32_t *)(&(block[i])));
		i += sha->len_msg;
	}
}
