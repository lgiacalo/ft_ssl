#include "ft_ssl.h"

void	print_all(void)
{
	print_ssl();
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

void	print_state(unsigned int state[4])
{
	ft_printf("\n********** Display State: **********\n");
	for (int i = 0; i < 4; i++)
		ft_printf("%c: %#.8x\n", (int)('A') + i, state[i]);
	ft_printf("************************************\n");
	ft_printf("************************************\n");
}

void	print_state_4int(int a, int b, int c, int d)
{
	ft_printf("\n********** Display State: **********\n");
	ft_printf("%c: %#.8x\n", (int)('A'), a);
	ft_printf("%c: %#.8x\n", (int)('B'), b);
	ft_printf("%c: %#.8x\n", (int)('C'), c);
	ft_printf("%c: %#.8x\n", (int)('D'), d);
	ft_printf("************************************\n");
	ft_printf("************************************\n");
}

void	print_sinus(void)
{
	ft_printf("\n********************** Display State: **********************\n");
	for (int i = 0; i < 64; i++)
	{
		if (i && !(i % 16))
			ft_printf("\n");
		ft_printf("%#.8x ", k[i]);
	}
	ft_printf("\n***********************************************************\n\n");
}

void	print_info_func4(int a, int b, int c, int d, int x, int i, int s, int sin)
{
	ft_printf("\n********** Display Info func: **********\n");
	ft_printf("%c: %#.8x\n", (int)('A'), a);
	ft_printf("%c: %#.8x\n", (int)('B'), b);
	ft_printf("%c: %#.8x\n", (int)('C'), c);
	ft_printf("%c: %#.8x\n", (int)('D'), d);
	ft_printf("x[%d] = [%d]\n", i, x);
	ft_printf("SS = [%d]\n", s);
	ft_printf("Sin: %#.8x\n", sin);

	ft_printf("************************************\n");
}

void	print_info_func(unsigned int state[4], int x, int i, int s, int sin)
{
	ft_printf("\n********** Display Info func: **********\n");
	for (int i = 0; i < 4; i++)
		ft_printf("%c: %#.8x\n", (int)('A') + i, state[i]);
	ft_printf("x[%d] = [%d]\n", i, x);
	ft_printf("SS = [%d]\n", s);
	ft_printf("Sin: %#.8x\n", sin);

	ft_printf("\n************************************\n");
}





