/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_function_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_sha.h"

void		message_schedule512(uint64_t *block, uint64_t w[80])
{
	int	t;

	t = -1;
	while (++t < 16)
		w[t] = reverse64(block[t]);
	t--;
	while (++t < 80)
		w[t] = ssig11(w[t - 2]) + w[t - 7] + ssig00(w[t - 15]) + w[t - 16];
}

void		message_schedule256(uint32_t *block, uint32_t w[64])
{
	int	t;

	t = -1;
	while (++t < 16)
		w[t] = reverse32(block[t]);
	t--;
	while (++t < 64)
		w[t] = ssig1(w[t - 2]) + w[t - 7] + ssig0(w[t - 15]) + w[t - 16];
}

uint64_t	chh(uint64_t x, uint64_t y, uint64_t z)
{
	return (((x) & (y)) ^ ((~x) & (z)));
}

uint32_t	ch(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ ((~x) & (z)));
}
