/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

/*
**	COMMANDS
*/

# define CMD_MD5	"md5"
# define CMD_SHA256	"sha256"

/*
**	OPTIONS
*/

# define OPT_STR	"pqsr"
# define OPT_P		(1 << 0)
# define OPT_Q		(1 << 1)
# define OPT_S		(1 << 2)
# define OPT_R		(1 << 3)

typedef struct		s_arg
{
	char		*name;
	char		*str;
	char		*checksum;
	struct s_arg	*next;
}			t_arg;

typedef struct		s_ssl
{
	char		*cmd;
	int		opt;
	int		ret;
	struct s_arg	*list;
}			t_ssl;

t_ssl	*getssl(void);
void	init_ssl(void);

/*
**	Print Error
*/

int	print_usage(void);
int	print_usage_commands(char *cmd);
int	print_illegal_option(char opt);
int	print_requires_args(char opt);

/*
**	Print structure
*/

void	print_ssl(void);
void	print_arg_list(void);
void	print_arg(t_arg *list);
void	print_all(void);

#endif
