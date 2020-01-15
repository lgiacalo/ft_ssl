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
