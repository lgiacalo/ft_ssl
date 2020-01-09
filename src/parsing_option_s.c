#include "ft_ssl.h"


void	MD5_transform(unsigned int	*block)
{
	print_block((char *)block);
	ft_printf("Function MD5_transform\n");
	ft_printf("string: %i[", getssl()->size);


	t_ssl	*ssl;
	unsigned int		state_temp[4], tmp, func, ind;


	ssl = getssl();
	ft_memcpy(state_temp, ssl->state, (sizeof(int) * 4));

	for (int i = 0; i < 64; i++)
	{
		if (i < 16)
		{
			func = func_f(state_temp[1], state_temp[2] , state_temp[3]);
			ind = i;
			// print_info_func(state_temp, block[ind], ind, r[i], k[i]);
		}
		else if (i < 32)
		{
			func = func_g(state_temp[1], state_temp[2], state_temp[3]);
			ind = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			func = func_h(state_temp[1], state_temp[2], state_temp[3]);
			ind = (3 * i + 5) % 16;
		}
		else
		{
			func = func_i(state_temp[1], state_temp[2], state_temp[3]);
			ind = (7 * i) % 16;
		}


		func = state_temp[0] + func + block[ind] + k[i];
		state_temp[0] = state_temp[1] + ROTAT_LEFT(func, r[i]);


		// state_temp[0] = state_temp[1] + ROTAT_LEFT(state_temp[0] + func + block[ind] + k[i], r[i]);

		tmp = state_temp[0];
		state_temp[0] = state_temp[3];
		state_temp[3] = state_temp[2];
		state_temp[2] = state_temp[1];
		state_temp[1] = tmp;

		// if (i < 6)
		// {
		// 	ft_printf("\nBoucle i = %d", i);
		// 	print_state(state_temp);
		// }
	}

	print_state(getssl()->state);

	for (int i = 0; i < 4; i++)
		ssl->state[i] += state_temp[i];

	print_state(getssl()->state);
	// print_state(state_temp);

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
		MD5_transform((unsigned int *)(&(ssl->buf[0])));
		ft_bzero(ssl->buf, 64);
		ft_memcpy(ssl->buf, PADDING + 1, 56);
	}
	ssl->size *= 8;
	ft_memcpy(ssl->buf + 56, (char *)(&(ssl->size)), 8);
	MD5_transform((unsigned int *)(&(ssl->buf[0])));

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
