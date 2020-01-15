/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
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

int	read_arguments(char *arg)
{
	int		fd;
	char	buff[SIZE_READ];
	size_t	size;

	if ((fd = open(arg, O_RDONLY)) == -1)
		return (print_no_file(arg));
	while ((size = read(fd, buff, SIZE_READ)) >= 0)
	{
		gestion_block(buff, size, (size != SIZE_READ) ? 63 : 0);
		if (size != SIZE_READ)
		{
			gestion_last_block(buff, size);
			break ;
		}
		ft_bzero(buff, SIZE_READ);
	}
	close(fd);
	display_hash(arg);
	return (0);
}

int	read_arguments_sha(char *arg)
{
	int		fd;
	char	buff[SIZE_READ];
	size_t	size;

	if ((fd = open(arg, 'r')) == -1)
		return (print_no_file(arg));
	while ((size = read(fd, buff, SIZE_READ)) >= 0)
	{
		gestion_block256(buff, size, (size != SIZE_READ) ? 63 : 0);
		if (size != SIZE_READ)
		{
			gestion_last_block256(buff, size);
			break ;
		}
		ft_bzero(buff, SIZE_READ);
	}
	close(fd);
	display_hash256(arg);
	return (0);
}
