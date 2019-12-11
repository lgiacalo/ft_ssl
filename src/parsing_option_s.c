#include "ft_ssl.h"

int	record_string(char *str)
{
	ft_printf("Read string: [%s]\n", str);
	return (0);
}

int	read_string_option(char *str)
{
	ft_printf("Read string Optiong: option -s\n");

	getssl()->opt |= OPT_S;
	if (str && !(str[1]))
		return (-1);
	else
		record_string(str + 1);
		ft_printf("Enregistrement string: chaine collee\n");
	return (0);
}

int	read_string(char *str)
{
	ft_printf("Read string: option -s\n");
	ft_printf("Lecture arg suivant: [%s]\n", str);
	if (!str)
		return (print_requires_args('s'));
	record_string(str);

	return (0);
}