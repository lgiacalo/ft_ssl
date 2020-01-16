/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_sha.h"

/*
**	SHA
*/

int	gestion_string256(char *str)
{
	uint64_t	size;

	size = ft_strlen(str);
	if (getsha()->len_msg == 64)
	{
		gestion_block256(str, size, 63);
		gestion_last_block256(str, size);
		display_hash256(str);
	}
	else
	{
		gestion_block512(str, size, 127);
		gestion_last_block512(str, size);
		display_hash256(str);
	}
	return (0);
}

int	read_string_option256(char *str)
{
	if (str && !(str[1]))
		return (-1);
	else
		gestion_string256(str + 1);
	return (0);
}

int	read_string256(char *str)
{
	if (!str)
		return (print_requires_args('s'));
	gestion_string256(str);
	return (0);
}

/*
**	MD5
*/

int	gestion_string(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	gestion_block(str, size, 63);
	gestion_last_block(str, size);
	display_hash(str);
	return (0);
}

int	read_string(char *str, int opt)
{
	if (opt)
	{
		if (!str)
			return (print_requires_args('s'));
		gestion_string(str);
	}
	else
	{
		if (str && !(str[1]))
			return (-1);
		else
			gestion_string(str + 1);
	}
	return (0);
}
