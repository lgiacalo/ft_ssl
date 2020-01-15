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

/*
CH (x, y, z) = (x ET y) XOR ((PAS x) ET z)
      MAJ (x, y, z) = (x ET y) XOR (x ET z) XOR (y ET z)
      BSIG0 (x) = ROTR ^ 28 (x) XOR ROTR ^ 34 (x) XOR ROTR ^ 39 (x)
      BSIG1 (x) = ROTR ^ 14 (x) XOR ROTR ^ 18 (x) XOR ROTR ^ 41 (x)
      SSIG0 (x) = ROTR ^ 1 (x) XOR ROTR ^ 8 (x) XOR SHR ^ 7 (x)
      SSIG1 (x) = ROTR ^ 19 (x) XOR ROTR ^ 61 (x) XOR SHR ^ 6 (x)
*/

uint64_t	chh(uint64_t x, uint64_t y, uint64_t z)
{
	return (((x) & (y)) ^ ((~x) & (z)));
}

uint64_t	majj(uint64_t x, uint64_t y, uint64_t z)
{
	return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}

uint64_t	bsig00(uint64_t x)
{
	return ((rotate_right(x, 28)) ^ (rotate_right(x, 34))
		^ (rotate_right(x, 39)));
}

uint64_t	bsig11(uint64_t x)
{
	return ((rotate_right(x, 14)) ^ (rotate_right(x, 18))
		^ (rotate_right(x, 41)));
}

uint64_t	ssig00(uint64_t x)
{
	return ((rotate_right(x, 1)) ^ (rotate_right(x, 8))
		^ ((x >> 7)));
}

uint64_t	ssig11(uint64_t x)
{
	return ((rotate_right(x, 19)) ^ (rotate_right(x, 61))
		^ ((x >> 6)));
}
