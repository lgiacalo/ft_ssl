#include "ft_ssl.h"

int	record_string(char *str)
{
	ft_printf("Read string: [%s]\n", str);
	
	t_arg	*arg;

	arg = ft_lstnew_arg(NULL, str);
	ft_lstadd_arg(arg);
	return (0);
}

int	read_string_option(char *str)
{
	getssl()->opt |= OPT_S;
	if (str && !(str[1]))
		return (-1);
	else
		record_string(str + 1);
	return (0);
}

int	read_string(char *str)
{
	if (!str)
		return (print_requires_args('s'));
	record_string(str);
	return (0);
}