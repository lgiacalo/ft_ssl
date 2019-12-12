/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/07/12 14:58:21 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[00m"

# define BASE_2			"01"
# define BASE_8			"01234567"
# define BASE_10		"0123456789"
# define BASE_16		"0123456789abcdef"
# define FLAGS_CONV		"sSpdDioOuUxXcCb%"
# define FLAGS_LEN		"hlLjz"
# define FLAGS_ATT		"#0- +"

# define CONV_S			1
# define CONV_UP_S		2
# define CONV_P			4
# define CONV_D			8
# define CONV_UP_D		16
# define CONV_I			32
# define CONV_O			64
# define CONV_UP_O		128
# define CONV_U			256
# define CONV_UP_U		512
# define CONV_X			1024
# define CONV_UP_X		2048
# define CONV_C			4096
# define CONV_UP_C		8192
# define CONV_PERC		16384
# define CONV_E			32768
# define CONV_UP_E		65536
# define CONV_F			131072
# define CONV_UP_F		262144
# define CONV_G			524288
# define CONV_UP_G		1048576
# define CONV_A			2097152
# define CONV_UP_A		4194304
# define CONV_N			8388608
# define CONV_B			16777216
# define CONV_R			33554432

# define ATT_SHARP		1
# define ATT_ZERO		2
# define ATT_MINUS		4
# define ATT_SPACE		8
# define ATT_PLUS		16

# define WIDTH			1
# define WIDTH_STAR		2
# define WIDTH_STAR_M	4

# define PREC_POINT		1
# define PREC_STAR		2
# define PREC_STAR_M	4

# define LEN_HH			1
# define LEN_H			2
# define LEN_L			4
# define LEN_LL			8
# define LEN_UP_L		16
# define LEN_J			32
# define LEN_Z			64

#endif
