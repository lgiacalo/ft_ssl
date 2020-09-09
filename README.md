# FT_SSL

**ft_ssl_md5** is the first project in cryptographic branch of 42 School projects.

The goal is to create a program (written in C) that will combine functionality of **md5**, **openssl** and **shasum** Unix programs.

## Algorithms
The program handles encryption with several algorithms:
* md5
* SHA224
* SHA256
* SHA384
* SHA512

## How to run
	> git clone https://github.com/lgiacalo/ft_ssl.git ~/ft_ssl_md5
	> cd ~/ft_ssl_md5/
	> make
	> ./ft_ssl command [command opts] [command args]

The program reads both files and standard input like **md5**. It also provides multifunctional input like **openssl** (launch without any arguments).
It has the same command options (except -x) and syntax as **md5**.

## SizeOf
	- Char:			1 octet
	- Char*:		8 octets
	- Short:		2 octets
	- Int:			4 octets
	- Int*:			8 octets
	- Unsigned int:	4 octets
	- Long int:		8 octets
	- LL int:		8 octets
	- Size_t:		8 octets


```
struct stat	st_buf;
fstat(fd, &st_buf);
ft_printf("Taille fichier : [%d]\n\n", st_buf.st_size);
```
