/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sha512.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_sha.h"
#include <fcntl.h>

void	read_stdin_sha512(char *b, int p)
{
	char		*tmp;
	uint64_t	size;
	uint64_t	size_tt;

	size_tt = 0;
	tmp = (char *)b;
	while ((size = read(0, tmp, SIZE_READ - size_tt)) >= 0)
	{
		size_tt += size;
		if (size_tt == SIZE_READ || !size)
		{
			(p) ? write(1, b, size_tt) : 0;
			gestion_block512(b, size_tt, (!size) ? getsha()->len_msg - 1 : 0);
			if (!size)
			{
				gestion_last_block512(b, size_tt);
				break ;
			}
			ft_bzero(b, SIZE_READ);
			tmp = (char *)b;
			size_tt = 0;
		}
		else
			tmp += size;
	}
}
