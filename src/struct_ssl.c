
#include "ft_ssl.h"

t_ssl	*getssl(void)
{
	static t_ssl	ssl;

	return (&ssl);
}

void	init_ssl(void)
{
	t_ssl	*ssl;

	ssl = getssl();
	ssl->cmd = NULL;
	ssl->opt = -1;
	ssl->list = NULL;
	ssl->ret = 0;
}
