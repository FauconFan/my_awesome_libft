/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_family.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:29 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/05 11:29:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_center_printf(const char *restrict format, va_list va,
					char **answer, int *len_to_print)
{
	t_string_buffer		*sb;
	int					res;
	int					tampon;
	int					ret;

	if ((sb = new_string_buffer_normal("")) == 0)
		return (-1);
	if ((ret = process((char *)format, va, sb)) == -1)
		return (-1);
	if (ret == -2)
	{
		free_last(sb);
		tampon = build_str(sb, answer);
		free_string_buffer(sb);
		if (len_to_print != 0)
			*len_to_print = tampon;
		return (-2);
	}
	res = build_str(sb, answer);
	free_string_buffer(sb);
	if (len_to_print != 0)
		*len_to_print = res;
	return (res);
}

/*
**	ft_printf...
*/

int				ft_printf(const char *restrict format, ...)
{
	va_list				va;
	int					res;
	int					len_to_print;
	char				*to_print;

	if (format == 0 || *format == 0)
		return (0);
	va_start(va, format);
	if ((res = ft_center_printf(format, va, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	write(1, to_print, len_to_print);
	free(to_print);
	return (res == -2 ? -1 : res);
}

/*
**	ft_dprintf...
*/

int				ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list				va;
	int					res;
	int					len_to_print;
	char				*to_print;

	if (format == 0 || *format == 0)
		return (0);
	va_start(va, format);
	if ((res = ft_center_printf(format, va, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	write(fd, to_print, len_to_print);
	free(to_print);
	return (res == -2 ? -1 : res);
}

/*
**	ft_sprintf
*/

int				ft_sprintf(char **str, const char *restrict format, ...)
{
	va_list				va;
	int					res;
	char				*to_print;

	if (format == 0 || *format == 0 || str == 0)
		return (0);
	va_start(va, format);
	if ((res = ft_center_printf(format, va, &to_print, 0)) == -1)
		return (-1);
	va_end(va);
	*str = to_print;
	return (res == -2 ? -1 : res);
}

/*
**	ft_snprintf
**	can have some bugs with unicode...
*/

int				ft_snprintf(char **str, size_t size,
					const char *restrict format, ...)
{
	va_list				va;
	int					res;
	int					len_to_print;
	char				*to_print;
	int					len;

	if (format == 0 || *format == 0 || str == 0)
		return (0);
	va_start(va, format);
	if ((res = ft_center_printf(format, va, &to_print, &len_to_print)) == -1)
		return (-1);
	va_end(va);
	len = ft_min(size, len_to_print);
	*str = ft_strnew(len);
	ft_strncpy(*str, to_print, len);
	return (res == -2 ? -1 : res);
}
