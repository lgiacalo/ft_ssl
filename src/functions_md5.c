/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_md5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	func_f(int b, int c, int d)
{
	return (((b) & (c)) | ((~b) & (d)));
}

int	func_g(int b, int c, int d)
{
	return (((b) & (d)) | ((c) & (~d)));
}

int	func_h(int b, int c, int d)
{
	return ((b) ^ (c) ^ (d));
}

int	func_i(int b, int c, int d)
{
	return ((c) ^ ((b) | (~d)));
}

int	rotate_left(unsigned int x, int n)
{
	return (((x) << (n)) | ((x) >> (32 - (n))));
}
