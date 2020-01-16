/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_sha.h"

static void	init_work_variable512(uint64_t alp[8])
{
	t_sha	*sha;
	int		i;

	sha = getsha();
	i = -1;
	while (++i < 8)
		alp[i] = sha->statee[i];
}

static void	compute_inter_hash(uint64_t alp[8])
{
	t_sha	*sha;
	int		i;

	i = -1;
	sha = getsha();
	while (++i < 8)
		sha->statee[i] = sha->statee[i] + alp[i];
}

void		sha_transform512(uint64_t *block)
{
	uint64_t	w[80];
	uint64_t	alp[8];
	uint64_t	t1;
	uint64_t	t2;
	uint8_t		i;

	message_schedule512(block, w);
	init_work_variable512(alp);
	i = -1;
	while (++i < 80)
	{
		t1 = alp[7] + bsig11(alp[4]) + chh(alp[4], alp[5], alp[6])
		+ g_kk[i] + w[i];
		t2 = bsig00(alp[0]) + majj(alp[0], alp[1], alp[2]);
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

void		gestion_last_block512(char *block, uint64_t size)
{
	t_sha		*sha;
	uint64_t	mod;
	uint64_t	div;

	sha = getsha();
	mod = size % sha->len_msg;
	div = (size / sha->len_msg) * sha->len_msg;
	ft_memcpy(sha->buf, block + div, mod);
	ft_memcpy(sha->buf + mod, PADDING, sha->len_msg - mod);
	if (mod >= (sha->len_msg - sha->len_size))
	{
		sha_transform512((uint64_t *)(&(sha->buf[0])));
		ft_bzero(sha->buf, sha->len_msg);
		ft_memcpy(sha->buf, PADDING + 1, (sha->len_msg - sha->len_size));
	}
	sha->size = reverse64(sha->size);
	sha->size1 = reverse64(sha->size1);
	ft_memcpy(sha->buf + (128 - 8), (unsigned char *)(&(sha->size)), 8);
	ft_memcpy(sha->buf + (128 - 16), (unsigned char *)(&(sha->size1)), 8);
	sha_transform512((uint64_t *)(&(sha->buf[0])));
}

void		gestion_block512(char *block, uint64_t size, int add)
{
	t_sha		*sha;
	uint64_t	i;

	sha = getsha();
	sha->size += size * 8;
	if (sha->size < (size * 8))
		sha->size1++;
	i = 0;
	while ((i + ((add) ? sha->len_msg - 1 : 0)) < size)
	{
		sha_transform512((uint64_t *)(&(block[i])));
		i += sha->len_msg;
	}
}
