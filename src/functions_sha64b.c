/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_sha64b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	majj(uint64_t x, uint64_t y, uint64_t z)
{
	return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}

uint64_t	bsig00(uint64_t x)
{
	return ((rotate_right64(x, 28)) ^ (rotate_right64(x, 34))
		^ (rotate_right64(x, 39)));
}

uint64_t	bsig11(uint64_t x)
{
	return ((rotate_right64(x, 14)) ^ (rotate_right64(x, 18))
		^ (rotate_right64(x, 41)));
}

uint64_t	ssig00(uint64_t x)
{
	return ((rotate_right64(x, 1)) ^ (rotate_right64(x, 8))
		^ ((x >> 7)));
}

uint64_t	ssig11(uint64_t x)
{
	return ((rotate_right64(x, 19)) ^ (rotate_right64(x, 61))
		^ ((x >> 6)));
}
