/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:47 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int	gestion_string(char *str)
{
	size_t	size;
	t_ssl	*ssl;

	ft_printf("Read string: [%s]\n", str);
	ssl = getssl();
	size = ft_strlen(str);
	gestion_block(str, size);
	gestion_last_block(str, size);
	//TODO: gestion affichage
	ft_printf("[\"%s\"] : %.8x%.8x%.8x%.8x\n", str, (ssl->state[0]), \
		(ssl->state[1]), (ssl->state[2]), (ssl->state[3]));
	clean_ssl();
	return (0);
}

int	read_string_option(char *str)
{
	if (str && !(str[1]))
		return (-1);
	else
		gestion_string(str + 1);
	return (0);
}

int	read_string(char *str)
{
	if (!str)
		return (print_requires_args('s'));
	gestion_string(str);
	return (0);
}
