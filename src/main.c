#include "ft_ssl.h"

int	record_commands(char *cmd)
{
	t_ssl	*ssl;

	ssl = getssl();
	ssl->cmd = cmd;
	if (!strcmp(CMD_MD5, cmd))
		return (0);
	else if (!strcmp(CMD_SHA256, cmd))
		return (0);
	ssl->cmd = NULL;
	return (1);
}

void	read_stdin(void)
{
	ft_printf("Read sur l'entree standard !\n");
}

void	read_arguments(char *arg)
{
	ft_printf("Lecture des arguments\n");
}

int	read_string_option(char *str)
{
	ft_printf("Read strin Optiong: option -s\n");

	getssl()->opt |= OPT_S;
	if (str && !(str[1]))
		return (-1);
	else
		ft_printf("Enregistrement string: chaine collee\n");
	return (0);
}

int	read_string(char *str)
{
	ft_printf("Read string: option -s\n");
	ft_printf("Lecture arg suivant\n");
	if (!str)
		return (print_requires_args('s'));

	return (0);
}

int	record_option(char *str, int *opt)
{
	int	i;
	int	ind;

	i = 0;
	*opt = 0;
	if (str && (*str != '-'))
		return (0);
	while (str && str[++i])
	{
		if ((ind = ft_chrstr_ind(str[i], OPT_STR)) < 0)
			return (print_illegal_option(str[i]));
		if (!(getssl()->opt & OPT_P) && str[i] == 'p')
			read_stdin();
		else if (!(getssl()->opt & OPT_S) && str[i] == 's')
			return (read_string_option(str + i));
		getssl()->opt |= (1 << ind);

	}
	*opt = 1;
	return (0);
}

void	record(char **argv, int argc)
{
	int	i; 
	int	opt;

	i = 2; 
	opt = 1;
	while (i < argc)
	{
		if (opt && record_option(argv[i], &opt) == -1)
			read_string(argv[++i]);
		else
			read_arguments(argv[i]);
		i++;
	}
	for (int i = 0; i < argc; i++)
		ft_printf("in record_options %i: [%s]\n", i, argv[i]);
	
}

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 1)
		return (print_usage());
	for (int i = 0; i < argc; i++)
		printf("args %i: [%s]\n", i, argv[i]);

	init_ssl();
	if (record_commands(argv[1]))
		return (print_usage_commands(argv[1]));
	ft_printf("cmd : [%s]\n", getssl()->cmd);
	
	if (argc == 2)
		read_stdin();
	else
		record(argv, argc);
	return (0);
}
