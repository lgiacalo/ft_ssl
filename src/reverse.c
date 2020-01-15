/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	reverse64(uint64_t block)
{
	return ((block & 0x00000000000000FFUL) << 56
		| (block & 0x000000000000FF00UL) << 40
		| (block & 0x0000000000FF0000UL) << 24
		| (block & 0x00000000FF000000UL) << 8
		| (block & 0x000000FF00000000UL) >> 8
		| (block & 0x0000FF0000000000UL) >> 24
		| (block & 0x00FF000000000000UL) >> 40
		| (block & 0xFF00000000000000UL) >> 56);
}

uint32_t	reverse32(uint32_t block)
{
	uint32_t ret;

	ret = 0;
	ret += block << 24 & 0xff000000;
	ret += block << 8 & 0x00ff0000;
	ret += block >> 8 & 0x000ff00;
	ret += block >> 24 & 0xff;
	return (ret);
}

void		reverse32_block(uint32_t *block, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		block[i] = reverse32(block[i]);
		i++;
	}
}
