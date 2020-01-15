/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state_sha.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha.h"

void	init_state_sha224(uint32_t state[8])
{
	state[0] = STATE00;
	state[1] = STATE11;
	state[2] = STATE22;
	state[3] = STATE33;
	state[4] = STATE44;
	state[5] = STATE55;
	state[6] = STATE66;
	state[7] = STATE77;
}

void	init_state_sha256(uint32_t state[8])
{
	state[0] = STATE0;
	state[1] = STATE1;
	state[2] = STATE2;
	state[3] = STATE3;
	state[4] = STATE4;
	state[5] = STATE5;
	state[6] = STATE6;
	state[7] = STATE7;
}

void	init_state_sha384(uint64_t state[8])
{
	state[0] = 0xcbbb9d5dc1059ed8;
	state[1] = 0x629a292a367cd507;
	state[2] = 0x9159015a3070dd17;
	state[3] = 0x152fecd8f70e5939;
	state[4] = 0x67332667ffc00b31;
	state[5] = 0x8eb44a8768581511;
	state[6] = 0xdb0c2e0d64f98fa7;
	state[7] = 0x47b5481dbefa4fa4;
}

void	init_state_sha512(uint64_t state[8])
{
	state[0] = 0x6a09e667f3bcc908;
	state[1] = 0xbb67ae8584caa73b;
	state[2] = 0x3c6ef372fe94f82b;
	state[3] = 0xa54ff53a5f1d36f1;
	state[4] = 0x510e527fade682d1;
	state[5] = 0x9b05688c2b3e6c1f;
	state[6] = 0x1f83d9abfb41bd6b;
	state[7] = 0x5be0cd19137e2179;
}