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

int		rotate_left(int x, int n)
{
	return (((x) << (n)) | ((x) >> (32 - (n))));
}