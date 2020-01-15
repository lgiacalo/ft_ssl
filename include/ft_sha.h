/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA_H
# define FT_SHA_H

# define STATE00				0x6a09e667
# define STATE11				0xbb67ae85
# define STATE22				0x3c6ef372
# define STATE33				0xa54ff53a
# define STATE44				0x510e527f
# define STATE55				0x9b05688c
# define STATE66				0x1f83d9ab
# define STATE77				0x5be0cd19

static uint32_t		g_kk[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

typedef struct					s_sha
{
	char						*cmd;
	int							opt;
	int							ret;
	int							f;
	uint32_t	 				state[8];
	uint64_t 					size;
	char						buf[64];
	// char						buff[SIZE_READ];
}								t_sha;


/*
**	Prototypes
*/

void				record_sha(char **argv, int argc);
int					read_arguments_sha(char *arg);

int					read_string256(char *str);
int					read_string_option256(char *str);
int					gestion_string256(char *str);

/*
**	Function structure sha
*/

t_sha				*getsha(void);
void				clean_sha(void);
void				init_sha(void);

/*
**	Gestion sha256
*/

void			gestion_block256(char *block, unsigned int size, int add);
void			gestion_last_block256(char *block, unsigned int size);

void			display_hash256(char *name);


/*
**	Fonctions logiques - 32 BITS
*/

uint32_t			ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t			maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t			bsig0(uint32_t x);
uint32_t			bsig1(uint32_t x);
uint32_t			ssig0(uint32_t x);
uint32_t			ssig1(uint32_t x);

#endif
