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
	ft_printf("Cmd:\t\t%s\n", ssl->cmd);
	ft_printf("Opt:\t\t%.4b\n", ssl->opt);
	ft_printf("Ret:\t\t%i\n", ssl->ret);
	ft_printf("State[4]:\t%#llx - %#llx - %#llx - %#llx\n", ssl->state[0], ssl->state[1], ssl->state[2], ssl->state[3]);
	ft_printf("Size:\t\t%i\n", ssl->size);
	ft_printf("List:\t\t%#llx\n", ssl->list);
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
	ft_printf("Short:\t\t%u octets\n", sizeof(short));
	ft_printf("Int:\t\t%u octets\n", sizeof(int));
	ft_printf("Int*:\t\t%u octets\n", sizeof(int*));
	ft_printf("Unsigned int:\t%u octets\n", sizeof(unsigned int));
	ft_printf("Long int:\t%u octets\n", sizeof(long int));
	ft_printf("Long long int:\t%u octets\n", sizeof(long long int));
	ft_printf("Size_t:\t\t%i octets\n", sizeof(size_t));
	ft_printf("***************************************\n");
}

void	print_block(char *block)
{
	if (!block)
		return ;
	ft_printf("\n**************** Display Block: ****************\n");
	for (int i = 0; i < 64; i++)
	{
		if (i && !(i % 16))
			ft_printf("\n");
		ft_printf("%.2x ", (unsigned char)block[i]);
	}
	ft_printf("\n************************************************\n");
	ft_printf("\n");
}

void	print_state(int state[4])
{
	ft_printf("\n********** Display State: **********\n");
	for (int i = 0; i < 4; i++)
		ft_printf("%c: %#.8x\n", (int)('A') + i, state[i]);
	ft_printf("\n************************************\n");
}

void	print_sinus(void)
{
	ft_printf("\n********** Display State: **********\n");
	for (int i = 0; i < 64; i++)
	{
		if (i && !(i % 16))
			ft_printf("\n");
		ft_printf("%#.8x ", k[i]);
	}
}






