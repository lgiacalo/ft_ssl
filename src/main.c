#include "ft_ssl.h"


int		main(int argc, char **argv)
{
	int	i;

	ft_printf("BUFSIZ = [%d]\n", BUFSIZ);

	i = -1;
	if (argc == 1)
		return (print_usage());
	// for (int i = 0; i < argc; i++)
	// 	printf("args %i: [%s]\n", i, argv[i]);
	init_ssl();
	if (record_commands(argv[1]))
		return (print_usage_commands(argv[1]));
	if (argc == 2)
		gestion_stdin();
	else
		record(argv, argc);


	ft_printf("\n\n\n\tREEL md5: \n");
	md5_real(argc, argv);

	return (0);
}
