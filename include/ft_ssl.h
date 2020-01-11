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
# include <math.h>

# include "libft.h"
# include "ft_md5.h"

/*
**	COMMANDS
*/

# define CMD_MD5				"md5"
# define CMD_SHA256				"sha256"

/*
**	OPTIONS
*/

# define OPT_STR				"pqsr"
# define OPT_P					(1 << 0)
# define OPT_Q					(1 << 1)
# define OPT_S					(1 << 2)
# define OPT_R					(1 << 3)
# define OPT_PP					(1 << 4)

/*
**	Constantes
*/

# define SIZE_READ				1024

typedef struct					s_ssl
{
	char						*cmd;
	int							opt;
	int							ret;
	unsigned int 				state[4];
	long int 					size;
	char						buf[64];
	char						buff[SIZE_READ];
}								t_ssl;

/*
**	Function structure ssl
*/

t_ssl							*getssl(void);
void							init_ssl(void);
void							clean_ssl(void);

/*
**	Parsing
*/

void							record(char **argv, int argc);
int								record_option(char *str);

int								read_string(char *str);
int								read_string_option(char *str);
int								gestion_string(char *str);

int								read_arguments(char *arg);
int								record_commands(char *cmd);

void							read_stdin(char *buff);
int								gestion_stdin(void);

/*
**	Reverse
*/

unsigned int					reverse(unsigned int block);
void							reverse_block(unsigned int *block);


/*
**	Print Error
*/

int								print_usage(void);
int								print_usage_commands(char *cmd);
int								print_illegal_option(char opt);
int								print_requires_args(char opt);
int								print_no_file(char *str);

/*
**	Print structure
*/

void	print_ssl(void);
void	print_all(void);
void	print_sizeof(void);
void	print_block(char *block);
void	print_state(unsigned int state[4]);
void	print_state_4int(int a, int b, int c, int d);
void	print_sinus(void);
void	print_info_func4(int a, int b, int c, int d, int x, int i, int s, int sin);
void	print_info_func(unsigned int state[4], int x, int i, int s, int sin);

#endif
