# ft_ssl


**************** Sizeof ***************
Char:		1 octet
Char*:		8 octets
Short:		2 octets
Int:		4 octets
Int*:		8 octets
Unsigned int:	4 octets
Long int:	8 octets
Long long int:	8 octets
Size_t:		8 octets
***************************************



	struct stat	st_buf;
	fstat(fd, &st_buf);
	ft_printf("Taille fichier : [%d]\n\n", st_buf.st_size);
