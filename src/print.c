#include "ft_ssl.h"

int	print_requires_args(char opt)
{
	ft_printf("ft_ssl: option requires an argument -- %c\n", opt);
	print_usage();
	getssl()->ret = 1;
	return (1);
}

int	print_illegal_option(char opt)
{
	ft_printf("ft_ssl: illegal option -- %c\n", opt);
	print_usage();
	getssl()->ret = 1;
	return (1);
}

int	print_usage(void)
{
	ft_printf("Usage: ft_ssl commands [commands opt] [commands args]\n");
	return (1);
}

int	print_usage_commands(char *cmd)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", cmd);
	ft_printf("\nStandard commands:\n\n");
	ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\n");
	return (1);
}
