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

void			message_schedule256(uint32_t *block, uint32_t w[64])
{
	int	t;

	t = -1;
	while (++t < 16)
		w[t] = reverse(block[t]);
	t--;
	while (++t < 64)
		w[t] = ssig1(w[t - 2]) + w[t - 7] + ssig0(w[t - 15]) + w[t - 16];
}

void			init_work_variable256(uint32_t alp[8])
{
	t_sha	*sha;
	int		i;

	sha = getsha();
	i = -1;
	while (++i < 8)
		alp[i] = sha->state[i];
}

void	compute_inter_hash(uint32_t alp[8])
{
	t_sha	*sha;
	int	i;

	i= -1;
	sha = getsha();
	while (++i < 8)
		sha->state[i] = sha->state[i] + alp[i];
}


void			sha_transform256(uint32_t *block)
{
	t_sha		*sha;
	uint32_t	w[64];
	uint32_t	alp[8];
	uint32_t	t1, t2;
	// uint8_t 	i;

	// ft_printf("Sha_transform256()\n");
	// print_block((char *)block);
	sha = getsha();
	message_schedule256(block, w);
	// print_uint32_64(w);

	init_work_variable256(alp);
	// print_state_sha256(alp);

	// i = 0;
	// while (i < 64)
	for (int i = 0; i < 64; i++)
	{
		t1 = alp[7] + bsig1(alp[4]) + ch(alp[4], alp[5], alp[6])+ g_kk[i] + w[i];
		t2 = bsig0(alp[0]) + maj(alp[0], alp[1], alp[2]);
		alp[7] = alp[6];
		alp[6] = alp[5];
		alp[5] = alp[4];
		alp[4] = alp[3] + t1;
		alp[3] = alp[2];
		alp[2] = alp[1];
		alp[1] = alp[0];
		alp[0] = t1 + t2;
		// ft_printf("\nI = [%d] / t1[%#.8x] / t2[%#.8x]", i, t1, t2);
		// print_state_sha256(alp);
	}

	compute_inter_hash(alp);
	// print_state_sha256(getsha()->state);
}

void			gestion_last_block256(char *block, unsigned int size)
{
	t_sha	*sha;
	int		mod;
	int		div;

	ft_printf("Gestion last block sha256\n");
	sha = getsha();
	mod = size % 64;
	div = (size / 64) * 64;
	ft_memcpy(sha->buf, block + div, mod);
	ft_memcpy(sha->buf + mod, PADDING, 64 - mod);
	if (mod >= 56)
	{
		sha_transform256((uint32_t *)(&(sha->buf[0])));
		ft_bzero(sha->buf, 64);
		ft_memcpy(sha->buf, PADDING + 1, 56);
	}
	sha->size *= 8;

	sha->size = reverse64(sha->size);
	ft_memcpy(sha->buf + 56, (unsigned char *)(&(sha->size)), 8);
	sha_transform256((unsigned int *)(&(sha->buf[0])));
	// reverse_block(sha->state, 8);
}

void			gestion_block256(char *block, unsigned int size, int add)
{
	t_sha			*sha;
	unsigned int	i;

	ft_printf("\nGestion block sha256 - size[%d]\n", size);
	// print_block(block);
	sha = getsha();
	sha->size += size;
	i = 0;
	while ((i + add) < size)
	{
		// ft_printf("dans la boucle - gestion block sha256\n");
		sha_transform256((uint32_t *)(&(block[i])));
		i += 64;
	}
}

