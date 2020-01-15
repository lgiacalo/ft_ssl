#include "ft_ssl.h"
#include "ft_sha.h"

void	print_uint64_80(uint64_t w[80])
{
	ft_printf("\n*********** Structure: s_ssl **********\n");
	for (int i = 0; i < 80; i++)
	{
		if (!(i % 8))
			ft_printf("\n");
		ft_printf("%s%#.16x ", (w[i]) ? "" : "0x", w[i]);
	}
	ft_printf("\n***************************************\n");
}

void	print_state_sha512(uint64_t state[8])
{
	ft_printf("\n******** Display State[8] SHA : ********\n");
	for (int i = 0; i < 8; i++)
		ft_printf("%c: %#.16x ", (int)('A') + i, state[i]);
	// ft_printf("\n****************************************\n");
	ft_printf("\n");
}

void	print_uint32_64(uint32_t w[64])
{
	ft_printf("\n*********** Structure: s_ssl **********\n");
	for (int i = 0; i < 64; i++)
	{
		if (!(i % 8))
			ft_printf("\n");
		ft_printf("%s%#.8x ", (w[i]) ? "" : "0x", w[i]);
	}
	ft_printf("\n***************************************\n");
}

void	print_all(void)
{
	print_ssl();
}

void	print_sha(void)
{
	t_sha	*sha;

	sha = getsha();
	ft_printf("\n*********** Structure: s_sha **********\n");
	ft_printf("Cmd:\t\t%s\n", sha->cmd);
	ft_printf("Version:\t%d\n", sha->version);
	ft_printf("Opt:\t\t%.4b\n", sha->opt);
	ft_printf("Ret:\t\t%i\n", sha->ret);
	ft_printf("State[4]:\t%#llx - %#llx - %#llx - %#llx\n", sha->state[0], sha->state[1], sha->state[2], sha->state[3]);
	ft_printf("Size:\t\t%i\n", sha->size);
	ft_printf("Len msg:\t%i\n", sha->len_msg);
	ft_printf("Len size:\t%i\n", sha->len_size);
	ft_printf("***************************************\n");
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
	ft_printf("Unsigned Long long int:\t%u octets\n", sizeof(unsigned long long int));
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

void	print_state_sha256(unsigned int state[8])
{
	ft_printf("\n******** Display State[8] SHA : ********\n");
	for (int i = 0; i < 8; i++)
		ft_printf("%c: %#.8x ", (int)('A') + i, state[i]);
	// ft_printf("\n****************************************\n");
	ft_printf("\n");
}

void	print_state(unsigned int state[4])
{
	ft_printf("\n********** Display State: **********\n");
	for (int i = 0; i < 4; i++)
		ft_printf("%c: %#.8x", (int)('A') + i, state[i]);
	ft_printf("************************************\n");
	ft_printf("************************************\n");
}

void	print_state_8int(int a, int b, int c, int d, int e, int f, int g, int h)
{
	ft_printf("\n********** Display State 8: **********\n");
	ft_printf("%c: %#.8x ", (int)('A'), a);
	ft_printf("%c: %#.8x ", (int)('B'), b);
	ft_printf("%c: %#.8x ", (int)('C'), c);
	ft_printf("%c: %#.8x ", (int)('D'), d);
	ft_printf("%c: %#.8x ", (int)('E'), e);
	ft_printf("%c: %#.8x ", (int)('F'), f);
	ft_printf("%c: %#.8x ", (int)('G'), g);
	ft_printf("%c: %#.8x ", (int)('H'), h);
	ft_printf("\n");
	// ft_printf("\n**************************************\n");
}

void	print_state_4int(int a, int b, int c, int d)
{
	ft_printf("\n********** Display State 4: **********\n");
	ft_printf("%c: %#.8x\n", (int)('A'), a);
	ft_printf("%c: %#.8x\n", (int)('B'), b);
	ft_printf("%c: %#.8x\n", (int)('C'), c);
	ft_printf("%c: %#.8x\n", (int)('D'), d);
	ft_printf("**************************************\n\n");
	ft_printf("************************************\n");
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





