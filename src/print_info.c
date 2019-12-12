#include "ft_ssl.h"

void	print_all(void)
{
	print_ssl();
	print_arg_list();
}

void	print_ssl(void)
{
	t_ssl	*ssl;

	ssl = getssl();
	ft_printf("\n*********** Structure: s_ssl **********\n");
	ft_printf("Cmd:\t%s\n", ssl->cmd);
	ft_printf("Opt:\t%.4b\n", ssl->opt);
	ft_printf("Ret:\t%i\n", ssl->ret);
	ft_printf("List:\t%#llx\n", ssl->list);
	ft_printf("***************************************\n");
}

void	print_arg(t_arg *list)
{
	ft_printf("Addr:\t\t%p\n", list);
	ft_printf("Name:\t\t%s\n", list->name);
	ft_printf("Str:\t\t%.20s%s\n", list->str, (ft_strlen(list->str) > 20) ? "..." : "");
	ft_printf("Checksum:\t%s\n", list->checksum);
	ft_printf("Next:\t\t%#llx\n", list->next);
}

void	print_arg_list(void)
{
	t_arg	*list;

	list = getssl()->list;
	ft_printf("\n******** Display Struct: s_arg ********\n");
	if (!list)
		ft_printf("List vide !\n");
	for (int i = 0; list; i++)
	{
		ft_printf("------ List n*%i ------\n", i);
		print_arg(list);
		list = list->next;
	}
	ft_printf("***************************************\n");
}

void	print_sizeof(void)
{
	ft_printf("\n**************** Sizeof ***************\n");
	ft_printf("Char:\t\t%u octet\n", sizeof(char));
	ft_printf("Char*:\t\t%u octets\n", sizeof(char*));
	ft_printf("Int:\t\t%u octets\n", sizeof(int));
	ft_printf("Int*:\t\t%u octets\n", sizeof(int*));
	ft_printf("Unsigned int:\t%u octets\n", sizeof(unsigned int));
	ft_printf("Long int:\t%u octets\n", sizeof(long int));
	ft_printf("Long long int:\t%u octets\n", sizeof(long long int));
	ft_printf("***************************************\n");
}
