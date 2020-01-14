/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <fcntl.h>

static void	read_stdin_sha(char *buff)
{
	char	*tmp;
	size_t	size;
	size_t	size_tt;

	ft_printf("read stdin sha\n");
	size_tt = 0;
	tmp = (char *)buff;
	while ((size = read(0, tmp, SIZE_READ - size_tt)) >= 0)
	{
		size_tt += size;
		if (size_tt == SIZE_READ || !size)
		{
			write(1, buff, size_tt);
			gestion_block256(buff, size_tt, (!size) ? 63 : 0);
			if (!size)
			{
				gestion_last_block256(buff, size_tt);
				break ;
			}
			ft_bzero(buff, SIZE_READ);
			tmp = (char *)buff;
			size_tt = 0;
		}
		else
			tmp += size;
	}
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

static int		gestion_stdin_sha(void)
{
	t_ssl	*ssl;
	char	buff[SIZE_READ];

	ssl = getssl();
	if (ssl->opt & OPT_PP)
		return (gestion_string(""));
	ssl->opt |= (1 << 4);
	ssl->opt |= (1 << 0);
	read_stdin_sha(buff);
	display_hash256(NULL);
	return (0);
}

int	gestion_string256(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	gestion_block256(str, size, 63);
	gestion_last_block256(str, size);
	display_hash256(str);
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


// /*
// **	si -pp alors entre standard + ""
// */

static int		record_option256(char *str)
{
	int	i;
	int	ind;

	i = 0;
	while (str && str[++i])
	{
		if ((ind = ft_chrstr_ind(str[i], OPT_STR)) < 0)
			return (print_illegal_option(str[i]));
		getsha()->opt |= (1 << ind);
		if (str[i] == 'p')
			gestion_stdin_sha();
		else if (str[i] == 's')
			return (read_string_option256(str + i));
	}
	return (0);
}

void	record_sha256(char **argv, int argc)
{
	int	i;
	int	opt;

	i = 2;
	opt = 1;
	init_sha();
	while (i < argc)
	{
		if (opt && argv[i][0] == '-')
		{
			if (record_option256(argv[i]) == -1)
				read_string256(argv[++i]);
		}
		else
		{
			opt = 0;
			read_arguments_sha(argv[i]);
		}
		i++;
	}
	if (argc == 2)
		gestion_stdin_sha();
}
