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
	ft_printf("***********Structure s_ssl***********\n");
	ft_printf("Cmd:\t%s\n", ssl->cmd);
	ft_printf("Opt:\t%b\n", ssl->opt);
	ft_printf("Ret:\t%i\n", ssl->ret);
	ft_printf("List:\t%llx\n", ssl->list);
	ft_printf("**************************************\n");
}

void	print_arg(t_arg *list)
{
	ft_printf("Name:\t%s\n", list->name);
	ft_printf("Str:\t%s\n", list->str);
	ft_printf("Checksum:\t%s\n", list->checksum);
	ft_printf("Next:\t%llx\n", list->next);
}

void	print_arg_list(void)
{
	t_arg	*list;

	list = getssl()->list;
	ft_printf("************Display Struct s_arg***********\n");
	if (!list)
		ft_printf("List vide !\n");
	for (int i = 0; list; i++)
	{
		ft_printf("------ List n*%i ------\n", i);
		print_arg(list);
		list = list->next;
	}
}
