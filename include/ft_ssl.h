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

/*
**	COMMANDS
*/

# define CMD_MD5		"md5"
# define CMD_SHA224		"sha224"
# define CMD_SHA256		"sha256"
# define CMD_SHA384		"sha384"
# define CMD_SHA512		"sha512"

# define NB_HASH		5

/*
**	OPTIONS
*/

# define OPT_STR		"pqsr"
# define OPT_P			1
# define OPT_Q			2
# define OPT_S			4
# define OPT_R			8
# define OPT_PP			16

/*
**	Constantes
*/

# define SIZE_READ		1024

static unsigned char	g_pad[128] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

typedef struct			s_ssl
{
	char				*cmd;
	int					opt;
	int					ret;
	int					f;
	unsigned int		state[4];
	uint64_t			size;
	char				buf[64];
	int					nb;
}						t_ssl;

typedef struct			s_hash
{
	void				(*func)(char **argv, int argc);
	char				*name;
}						t_hash;

void					record_sha(char **argv, int argc);
void					record_md5(char **argv, int argc);

static t_hash			g_hash[] =
{
	{record_md5, "md5"},
	{record_sha, "sha224"},
	{record_sha, "sha256"},
	{record_sha, "sha384"},
	{record_sha, "sha512"},
	{NULL, NULL}
};

/*
**	Function structure ssl
*/

t_ssl					*getssl(void);
void					init_ssl(void);
void					clean_ssl(void);

/*
**	Gestion MD5
*/

void					gestion_block(char *block, uint32_t size, int add);
void					gestion_last_block(char *block, uint32_t size);
void					display_hash(char *name);

/*
**	Gestion sha256
*/

void					gestion_block256(char *block, uint64_t size,
	int add);
void					gestion_last_block256(char *block, uint64_t size);
void					message_schedule256(uint32_t *block, uint32_t w[64]);
void					display_hash256(char *name);

/*
**	Gestion sha512
*/

void					gestion_block512(char *block, uint64_t size, int add);
void					gestion_last_block512(char *block, uint64_t size);
void					message_schedule512(uint64_t *block, uint64_t w[80]);

/*
**	Reverse
*/

uint32_t				rotate_left(uint32_t x, int n);
uint32_t				rotate_right(uint32_t x, int n);
uint64_t				rotate_left64(uint64_t x, int n);
uint64_t				rotate_right64(uint64_t x, int n);

uint64_t				reverse64(uint64_t block);
uint32_t				reverse32(uint32_t block);
void					reverse32_block(uint32_t *block, int ind);

/*
**	Print Error
*/

int						print_usage(void);
int						print_usage_commands(char *cmd);
int						print_illegal_option(char opt);
int						print_requires_args(char opt);
int						print_no_file(char *str);

/*
**	Utils
*/

int						tab_len(char **tab);
void					free_tab(char ***tab);

/*
**	Print structure
*/

void					print_uint64_80(uint64_t w[80]);
void					print_state_sha512(uint64_t state[8]);
void					print_block128(char *block);

void					print_uint32_64(uint32_t w[64]);
void					print_state_sha256(unsigned int state[8]);
void					print_state_8int(int a, int b, int c, int d,
	int e, int f, int g, int h);

void					print_ssl(void);
void					print_sha(void);
void					print_all(void);

void					print_block(char *block);
void					print_state(unsigned int state[4]);
void					print_state_4int(int a, int b, int c, int d);

void					print_info_func4(int a, int b, int c, int d,
	int x, int i, int s, int sin);
void					print_info_func(unsigned int state[4], int x,
	int i, int s, int sin);

#endif
