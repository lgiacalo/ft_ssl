/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ssl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_sha	*getsha(void)
{
	static t_sha	sha;

	return (&sha);
}


void	clean_sha(void)
{
	t_sha	*sha;

	sha = getsha();
	sha->state[0] = STATE00;
	sha->state[1] = STATE11;
	sha->state[2] = STATE22;
	sha->state[3] = STATE33;
	sha->state[4] = STATE44;
	sha->state[5] = STATE55;
	sha->state[6] = STATE66;
	sha->state[7] = STATE77;
	sha->size = 0;
	sha->opt &= 18;
	// ft_bzero(sha->buf, 64);
}

void	init_sha(void)
{
	t_sha	*sha;

	sha = getsha();
	sha->cmd = getssl()->cmd;
	sha->opt = 0;
	sha->ret = 0;
	sha->f = getssl()->f;
	sha->state[0] = STATE00;
	sha->state[1] = STATE11;
	sha->state[2] = STATE22;
	sha->state[3] = STATE33;
	sha->state[4] = STATE44;
	sha->state[5] = STATE55;
	sha->state[6] = STATE66;
	sha->state[7] = STATE77;
	sha->size = 0;
	// ft_bzero(ssha>buf, 64);
}