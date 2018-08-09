/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_family.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:34:29 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/09 09:46:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_center_printf(const char *format, va_list va,
					char **answer, int *len_to_print)
{
	t_pf_buffer			*pf;
	int					res;
	int					tampon;
	int					ret;

	pf = ft_create_pf_buffer();
	if ((ret = process((char *)format, va, pf)) == -1)
		return (-1);
	if (ret == -2)
	{
		tampon = to_string_n_free(&pf, answer, TRUE);
		if (len_to_print != 0)
			*len_to_print = tampon;
		return (-2);
	}
	res = to_string_n_free(&pf, answer, FALSE);
	if (len_to_print != 0)
		*len_to_print = res;
	return (res);
}

/*
**	ft_printf...
*/

int				ft_printf(const char *format, ...)
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

int				ft_dprintf(int fd, const char *format, ...)
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

int				ft_sprintf(char **str, const char *format, ...)
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
					const char *format, ...)
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
