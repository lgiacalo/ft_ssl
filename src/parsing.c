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
	ft_printf("Lecture des arguments: [%s]\n", arg);
}

int	record_option(char *str, int *opt)
{
	int	i;
	int	ind;

	i = 0;
	*opt = 0;
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
		if (opt && argv[i][0] == '-')
		{
			if (record_option(argv[i], &opt) == -1)
				read_string(argv[++i]);
		}
		else
		{
			opt = 0;
			read_arguments(argv[i]);
		}
		i++;
	}
}