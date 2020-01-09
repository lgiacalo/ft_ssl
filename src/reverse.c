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

unsigned int	reverse(unsigned int block)
{
	unsigned int ret;

	ret = 0;
	ret += block << 24 & 0xff000000;
	ret += block << 8 & 0xff0000;
	ret += block >> 8 & 0xff00;
	ret += block >> 24 & 0xff;
	return (ret);
}

void			reverse_block(unsigned int *block)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		block[i] = reverse(block[i]);
		i++;
	}
}
