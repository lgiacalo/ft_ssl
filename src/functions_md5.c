#include "ft_ssl.h"

int 	func_f(int b, int c, int d)
{
	return (((b) & (c)) | ((~b) & (d)));
}

int 	func_g(int b, int c, int d)
{
	return (((b) & (d)) | ((c) & (~d)));
}

int 	func_h(int b, int c, int d)
{
	return ((b)^(c)^(d));
}

int 	func_i(int b, int c, int d)
{
	return ((c) ^ ((b) | (~d)));
}

int		rotate_left(unsigned int x, int n)
{
	return (((x) << (n)) | ((x) >> (32-(n))));
}

unsigned int		reverse(unsigned int block)
{
	unsigned int ret;

	ret = 0;
	ret += block << 24 & 0xff000000;
	ret += block << 8 & 0xff0000;
	ret += block >> 8 & 0xff00;
	ret += block >> 24 & 0xff;
	return (ret);
}

void	reverse_block(unsigned int *block)
{
	int	i; 

	i = 0;
	while (i < 4)
	{
		block[i] = reverse(block[i]);
		i++;
	}
}