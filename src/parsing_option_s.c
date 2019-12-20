#include "ft_ssl.h"

void	MD5_transform(int	*block)
{
	print_block((char *)block);
	ft_printf("Function MD5_transform\n");

	ft_printf("string: %i[", getssl()->size);
	for (int i = 0; i < getssl()->size; i++)
		for (int j = 0; j < 4; j++)
			ft_printf("%c", (char)((char *)(&(block[i])))[j]);

}

void	gestion_last_block(char *block, unsigned int size)
{
	ft_printf("Fonction gestion last block\n");
	t_ssl	*ssl;
	int		mod;
	int		div;

	ssl = getssl();

	mod = size % 64;
	div = (size / 64) * 64;
	ft_memcpy(ssl->buf, block + div, mod);
	ft_memcpy(ssl->buf + mod, PADDING, 64 - mod);

	if (mod >= 56)
	{
		MD5_transform((int *)(&(ssl->buf[0])));
		ft_bzero(ssl->buf, 64);
		ft_memcpy(ssl->buf, PADDING + 1, 56);
	}
	ssl->size *= 8;
	ft_memcpy(ssl->buf + 56, (char *)(&(ssl->size)), 8);
	MD5_transform((int *)(&(ssl->buf[0])));

}

void	gestion_block(char *block, unsigned int size)
{
	ft_printf("Fonction gestion block\n");
	t_ssl			*ssl;
	unsigned int 	i;

	ssl = getssl();
	ssl->size += size;

	i = 0;
	while ((i + 63) < size)
	{
		MD5_transform((int *)(&(block[i])));
		i += 64;
	}
}

int	record_string(char *str)
{
	ft_printf("Read string: [%s]\n", str);
	

	size_t	size;

	size = ft_strlen(str);
	gestion_block(str, size);
	gestion_last_block(str, size);

	return (0);
}

int	read_string_option(char *str)
{
	getssl()->opt |= OPT_S;
	if (str && !(str[1]))
		return (-1);
	else
		record_string(str + 1);
	return (0);
}

int	read_string(char *str)
{
	if (!str)
		return (print_requires_args('s'));
	record_string(str);
	return (0);
}