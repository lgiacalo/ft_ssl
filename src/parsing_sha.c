/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sha.c                                      :+:      :+:    :+:   */
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


static void	read_stdin_sha(char *b, int p)
{
	char	*tmp;
	size_t	size;
	size_t	size_tt;

	size_tt = 0;
	tmp = (char *)b;
	while ((size = read(0, tmp, SIZE_READ - size_tt)) >= 0)
	{
		size_tt += size;
		if (size_tt == SIZE_READ || !size)
		{
			(p) ? write(1, b, size_tt) : 0;
			gestion_block256(b, size_tt, (!size) ? getsha()->len_msg - 1 : 0);
			if (!size)
			{
				gestion_last_block256(b, size_tt);
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

static int	gestion_stdin_sha(int p)
{
	t_sha	*sha;
	char	buff[SIZE_READ];

	sha = getsha();
	if (sha->opt & OPT_PP)
		return (gestion_string256("")); //ici
	sha->opt |= (1 << 4);
	sha->opt |= (1 << 0);
	(sha->len_msg == 64) ? read_stdin_sha(buff, p) : read_stdin_sha512(buff, p);
	display_hash256(NULL);
	return (0);
}

/*
**	si -pp alors entre standard + ""
*/

static int	record_option256(char *str)
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
			gestion_stdin_sha(1);
		else if (str[i] == 's')
			return (read_string_option256(str + i));
	}
	return (0);
}

void		record_sha(char **argv, int argc)
{
	int	i;
	int	opt;

	i = 2;
	opt = 1;
	init_sha();
	// print_state_sha256(getsha()->state);
	// print_state_sha512(getsha()->statee);
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
		gestion_stdin_sha(0);
}
