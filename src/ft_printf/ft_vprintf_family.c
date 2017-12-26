/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_family.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:24:49 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/15 14:32:43 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_vprintf(const char *format, va_list ap)
{
	int					res;
	int					len_to_print;
	char				*to_print;

	if (format == 0 || *format == 0)
		return (0);
	if ((res = ft_center_printf(format, ap, &to_print, &len_to_print)) == -1)
		return (-1);
	write(1, to_print, len_to_print);
	free(to_print);
	return (res == -2 ? -1 : res);
}

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	int					res;
	int					len_to_print;
	char				*to_print;

	if (format == 0 || *format == 0)
		return (0);
	if ((res = ft_center_printf(format, ap, &to_print, &len_to_print)) == -1)
		return (-1);
	write(fd, to_print, len_to_print);
	free(to_print);
	return (res == -2 ? -1 : res);
}

int				ft_vsprintf(char **str, const char *format, va_list ap)
{
	int					res;
	char				*to_print;

	if (format == 0 || *format == 0 || str == 0)
		return (0);
	if ((res = ft_center_printf(format, ap, &to_print, 0)) == -1)
		return (-1);
	*str = to_print;
	return (res == -2 ? -1 : res);
}

int				ft_vsnprintf(char **str, size_t size,
					const char *format, va_list ap)
{
	int					res;
	int					len_to_print;
	char				*to_print;
	int					len;

	if (format == 0 || *format == 0 || str == 0)
		return (0);
	if ((res = ft_center_printf(format, ap, &to_print, &len_to_print)) == -1)
		return (-1);
	len = ft_min(size, len_to_print);
	*str = ft_strnew(len);
	ft_strncpy(*str, to_print, len);
	return (res == -2 ? -1 : res);
}
