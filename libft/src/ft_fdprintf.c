/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 20:43:28 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:50:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	color(char *color, int size, int fd, unsigned int *i)
{
	ft_putstr_fd_nb(color, fd);
	*i += size - 1;
}

int			ft_flags_conv(char f_conv)
{
	int	ret;

	ret = ft_chrstr_ind(f_conv, "sSpdDioOuUxXcC%eEfFgGaAnbr");
	if (ret >= 0)
		return (1 << ret);
	else
		return (4096);
}

static int	ft_search(const char *format, va_list ap, unsigned int *i, int fd)
{
	t_flags			*flags;
	char			*chaine;
	int				count;
	unsigned int	k;

	(*i)++;
	k = *i;
	chaine = NULL;
	flags = NULL;
	flags = ft_memalloc(sizeof(t_flags) * 1);
	while ((format[*i] != '\0')\
		&& ((count = ft_chrstr_ind(format[*i], "#0-+ .*0123456789hljzL")) >= 0))
		(*i)++;
	if (format[*i] == '\0')
		return (0);
	flags->conv = ft_flags_conv(format[*i]);
	if (!(chaine = ft_strsub(format, k, (*i - k + 1))))
		return (-1);
	ft_flags_init(flags, chaine, ap);
	count = (ft_chrstr_ind(format[*i], FLAGS_CONV) >= 0)\
		? ft_flags(ap, flags, fd) : ft_conv_c((int)(format[*i]), flags, fd);
	ft_memdel((void **)&flags);
	ft_memdel((void **)&chaine);
	return (count);
}

static int	ft_color(const char *format, unsigned int *i, int fd)
{
	int	count;

	count = 8;
	if (!ft_strncmp((format + *i), "{red}", 5))
		color(PF_RED, 5, fd, i);
	else if (!ft_strncmp((format + *i), "{green}", 7))
		color(PF_GREEN, 7, fd, i);
	else if (!ft_strncmp((format + *i), "{yellow}", 8))
		color(PF_YELLOW, 8, fd, i);
	else if (!ft_strncmp((format + *i), "{blue}", 6))
		color(PF_BLUE, 6, fd, i);
	else if (!ft_strncmp((format + *i), "{purple}", 8))
		color(PF_PURPLE, 8, fd, i);
	else if (!ft_strncmp((format + *i), "{cyan}", 6))
		color(PF_CYAN, 6, fd, i);
	else if (!ft_strncmp((format + *i), "{eoc}", 5))
		color(PF_EOC, 5, fd, i);
	else
		count = ft_putchar_fd(format[*i], fd);
	return (count);
}

int			ft_fdprintf(int fd, const char *format, ...)
{
	va_list			ap;
	unsigned int	i;
	int				len;
	int				out;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if ((out = ft_search(format, ap, &i, fd)) == -1)
				return (-1);
			len += out;
		}
		else if (format[i] == '{')
			len += ft_color(format, &i, fd);
		else
			len += ft_putchar_fd(format[i], fd);
		if (format[i] != '\0')
			i++;
	}
	va_end(ap);
	return (len);
}
