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

int md5_real (int argc, char **argv);


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

/*
**	Constantes
*/

# define SIZE_READ	512

# define STATE0		0x67452301
# define STATE1		0xefcdab89
# define STATE2		0x98badcfe
# define STATE3		0x10325476

static unsigned char PADDING[64] = {
 0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static int r[64] = {
	7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
	5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
	4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
	6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};

static unsigned int k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};


typedef struct		s_arg
{
	char			*name;
	char			*str;
	char			checksum[32];
	struct s_arg	*next;
}					t_arg;

typedef struct		s_ssl
{
	char			*cmd;
	int				opt;
	int				ret;
	unsigned int 	state[4];
	long int 		size;
	char			buf[64];
	struct s_arg	*list;
}					t_ssl;

typedef struct		s_md5
{
	int 			bufint[16];
	char			bufchar[64];
}					t_md5;

/*
**	Function structure ssl
*/

t_ssl	*getssl(void);
void	init_ssl(void);
void	clean_ssl(void);


/*
**	Function structure arg
*/

t_arg	*ft_lstnew_arg(char *name, char *str);
void	ft_lstadd_arg(t_arg *new);

/*
**	Parsing
*/

void	record(char **argv, int argc);
int		record_option(char *str);

int		read_string(char *str);
int		read_string_option(char *str);
int		gestion_string(char *str);

int		read_arguments(char *arg);
void	read_stdin(void);
int		record_commands(char *cmd);


/*
**	Functions non lineaire MD5
*/

int 	func_f(int b, int c, int d);
int 	func_g(int b, int c, int d);
int 	func_h(int b, int c, int d);
int 	func_i(int b, int c, int d);

int		rotate_left(unsigned int x, int n);

/*
**	Reverse
*/

unsigned int	reverse(unsigned int block);
void			reverse_block(unsigned int *block);


/*
**	Gestion MD5
*/

void	gestion_block(char *block, unsigned int size, int add);
void	gestion_last_block(char *block, unsigned int size);

void			md5_transform(unsigned int *block);

void	display_hash(char *name);


/*
**	Print Error
*/

int		print_usage(void);
int		print_usage_commands(char *cmd);
int		print_illegal_option(char opt);
int		print_requires_args(char opt);
int		print_no_file(char *str);


/*
**	Print structure
*/

void	print_ssl(void);
void	print_arg_list(void);
void	print_arg(t_arg *list);
void	print_all(void);
void	print_sizeof(void);
void	print_block(char *block);
void	print_state(unsigned int state[4]);
void	print_state_4int(int a, int b, int c, int d);
void	print_sinus(void);
void	print_info_func4(int a, int b, int c, int d, int x, int i, int s, int sin);
void	print_info_func(unsigned int state[4], int x, int i, int s, int sin);



#endif
