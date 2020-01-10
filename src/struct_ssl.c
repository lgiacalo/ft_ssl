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

t_ssl	*getssl(void)
{
	static t_ssl	ssl;

	return (&ssl);
}

void	clean_ssl(void)
{
	t_ssl	*ssl;

	ssl = getssl();
	ssl->state[0] = STATE0;
	ssl->state[1] = STATE1;
	ssl->state[2] = STATE2;
	ssl->state[3] = STATE3;
	ssl->size = 0;
	ssl->opt ^= (1 << 2);
	ssl->opt ^= (1 << 0);
	ft_bzero(ssl->buf, 64);
}

void	init_ssl(void)
{
	t_ssl	*ssl;

	ssl = getssl();
	ssl->cmd = NULL;
	ssl->opt = 0;
	ssl->list = NULL;
	ssl->ret = 0;
	ssl->state[0] = STATE0;
	ssl->state[1] = STATE1;
	ssl->state[2] = STATE2;
	ssl->state[3] = STATE3;
	ssl->size = 0;
	ft_bzero(ssl->buf, 64);
}
