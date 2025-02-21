/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	rotate_left(uint32_t x, int n)
{
	return (((x) << (n)) | ((x) >> (32 - (n))));
}

uint32_t	rotate_right(uint32_t x, int n)
{
	return (((x) >> (n)) | ((x) << (32 - (n))));
}

uint64_t	rotate_left64(uint64_t x, int n)
{
	return (((x) << (n)) | ((x) >> (64 - (n))));
}

uint64_t	rotate_right64(uint64_t x, int n)
{
	return (((x) >> (n)) | ((x) << (64 - (n))));
}
