/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int				ind_block(int i)
{
	if (i < 16)
		return (i);
	else if (i < 32)
		return ((5 * i + 1) % 16);
	else if (i < 48)
		return ((3 * i + 5) % 16);
	return ((7 * i) % 16);
}

unsigned int	func_block(unsigned int *block, int i)
{
	if (i < 16)
		return (func_f(block[1], block[2], block[3]));
	else if (i < 32)
		return (func_g(block[1], block[2], block[3]));
	else if (i < 48)
		return (func_h(block[1], block[2], block[3]));
	return (func_i(block[1], block[2], block[3]));
}

void			md5_transform(unsigned int *block)
{
	t_ssl			*ssl;
	unsigned int	tmp[4];
	unsigned int	func;
	int				i;

	ssl = getssl();
	ft_memcpy(tmp, ssl->state, (sizeof(unsigned int) * 4));
	i = -1;
	while (++i < 64)
	{
		func = tmp[0] + func_block(tmp, i) + block[ind_block(i)] + k[i];
		tmp[0] = tmp[3];
		tmp[3] = tmp[2];
		tmp[2] = tmp[1];
		tmp[1] = tmp[1] + rotate_left(func, r[i]);
	}
	i = -1;
	while (++i < 4)
		ssl->state[i] += tmp[i];
}

void			gestion_last_block(char *block, unsigned int size)
{
	t_ssl	*ssl;
	int		mod;
	int		div;

	ssl = getssl();
	mod = size % 64;
	div = (size / 64) * 64;
	ft_memcpy(ssl->buf, block + div, mod);
	ft_memcpy(ssl->buf + mod, PADDING, 64 - mod);
	if (mod >= 56)
	{
		md5_transform((unsigned int *)(&(ssl->buf[0])));
		ft_bzero(ssl->buf, 64);
		ft_memcpy(ssl->buf, PADDING + 1, 56);
	}
	ssl->size *= 8;
	ft_memcpy(ssl->buf + 56, (char *)(&(ssl->size)), 8);
	md5_transform((unsigned int *)(&(ssl->buf[0])));
	reverse_block(ssl->state, 4);
}

void			gestion_block(char *block, unsigned int size, int add)
{
	t_ssl			*ssl;
	unsigned int	i;

	ssl = getssl();
	ssl->size += size;
	i = 0;
	while ((i + add) < size)
	{
		md5_transform((unsigned int *)(&(block[i])));
		i += 64;
	}
}
