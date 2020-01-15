/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_sha32b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	ch(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ ((~x) & (z)));
}

uint32_t	maj(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}

uint32_t	bsig0(uint32_t x)
{
	return ((rotate_right(x, 2)) ^ (rotate_right(x, 13))
		^ (rotate_right(x, 22)));
}

uint32_t	bsig1(uint32_t x)
{
	return ((rotate_right(x, 6)) ^ (rotate_right(x, 11))
		^ (rotate_right(x, 25)));
}

uint32_t	ssig0(uint32_t x)
{
	return ((rotate_right(x, 7)) ^ (rotate_right(x, 18))
		^ ((x >> 3)));
}

uint32_t	ssig1(uint32_t x)
{
	return ((rotate_right(x, 17)) ^ (rotate_right(x, 19))
		^ ((x >> 10)));
}
