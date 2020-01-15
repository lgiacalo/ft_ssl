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

static void	message_schedule256(uint64_t *block, uint64_t w[80])
{
	int	t;

	t = -1;
	while (++t < 16)
		w[t] = reverse32(block[t]);
	t--;
	while (++t < 80)
		w[t] = ssig11(w[t - 2]) + w[t - 7] + ssig00(w[t - 15]) + w[t - 16];
}

static void	init_work_variable256(uint64_t alp[8])
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

	print_block128((char *)block);
	message_schedule256(block, w);
	init_work_variable256(alp);
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
	//TODO: gestion size * 8 --> trop grand ? 
	sha->size *= 8;
	//TODO: gestion reverse64 * 2
	sha->size = reverse64(sha->size);
	//TODO: gestion write size*2 in buff // retirer les 8
	ft_memcpy(sha->buf + (sha->len_msg - sha->len_size + 8), (unsigned char *)(&(sha->size)), sha->len_size - 8);
	sha_transform512((uint64_t *)(&(sha->buf[0])));
}

void		gestion_block512(char *block, uint64_t size, int add)
{
	t_sha		*sha;
	uint64_t	i;

	sha = getsha();
	//TODO: gestion size dans 2 variables
	sha->size += size;
	i = 0;
	while ((i + ((add) ? sha->len_msg - 1 : 0)) < size)
	{
		sha_transform512((uint64_t *)(&(block[i])));
		i += sha->len_msg;
	}
}
