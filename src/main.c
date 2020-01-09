#include "ft_ssl.h"

int		reverse(int block)
{
	int ret;

	ret = 0;
	ret += block << 24 & 0xff000000;
	ret += block << 8 & 0xff0000;
	ret += block >> 8 & 0xff00;
	ret += block >> 24 & 0xff;
	return (ret);
}

void	test(void)
{
	char	str[64] = "Le Message Digest 5 est une fonction de hachage cryptographique";
	char	s1[9] = "ABCDEFGH";
	int 	nb[16];
	// char	s3[64];
	char	*s2;

	ft_printf("str[64] = [%s]\n", str);
	ft_printf("s1[4] = [%s]\n", s1);

	nb[0] = 0x44434241;
	nb[1] = 0x48474645;
	nb[2] = 0;
	ft_printf("[%p][%llx]\n", s1, nb[0]);
	s2 = (char *)(nb);
	ft_printf("s2 = [%s]\n", s2);
	nb[0] = *((int *)(s1 + 4));
	ft_printf("nb[0]: [%llx]\n", nb[0]);

	int i;

	i = 0;
	while (str[i])
	{
		if (!(i % 4))
			nb[i / 4] = *((int *)(str + i));
		i++;
	}
}


int		main(int argc, char **argv)
{
	int	i;


	i = -1;
	if (argc == 1)
		return (print_usage());
	for (int i = 0; i < argc; i++)
		printf("args %i: [%s]\n", i, argv[i]);

	init_ssl();
	print_sinus();
	if (record_commands(argv[1]))
		return (print_usage_commands(argv[1]));

	ft_printf("\n");
	print_state(getssl()->state);
	if (argc == 2)
		read_stdin();
	else
		record(argv, argc);


	print_ssl();
	// test();


	ft_printf("\n\n\n\tREEL md5: \n");
	md5_real(argc, argv);


	return (0);
}
