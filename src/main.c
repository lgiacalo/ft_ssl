#include "ft_ssl.h"


int		main(int argc, char **argv)
{
	int	i;


	i = -1;
	if (argc == 1)
		return (print_usage());
	for (int i = 0; i < argc; i++)
		printf("args %i: [%s]\n", i, argv[i]);

	init_ssl();
	// print_sinus();
	if (record_commands(argv[1]))
		return (print_usage_commands(argv[1]));

	// ft_printf("\n");
	// print_state(getssl()->state);
	if (argc == 2)
		read_stdin();
	else
		record(argv, argc);


	// print_ssl();


	ft_printf("\n\n\n\tREEL md5: \n");
	md5_real(argc, argv);


	return (0);
}
