/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:36:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/27 08:15:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				process_special_char(va_list va, t_treat_data *data,
						t_string_buffer *sb)
{
	wchar_t		wchar;
	char		*str;
	int			size;
	int			len;

	wchar = va_arg(va, wchar_t);
	size = ft_wcharlen(wchar);
	if (size > (int)MB_CUR_MAX)
		return (-2);
	len = ft_max(data->gabarit, 1);
	str = 0;
	if (len > 1)
		str = ft_strsetnew(size + len - 1, (data->zero_flag) ? '0' : ' ');
	else
		str = ft_strsetnew(size, (data->zero_flag) ? '0' : ' ');
	if (data->minus_flag)
		ft_fill_wstring_len(wchar, str, size);
	else
		ft_fill_wstring_len(wchar, str + len - 1, size);
	sb_append_special(sb, str, size + len - 1);
	free(str);
	return (0);
}

static char		*get_first_rep(va_list va, t_treat_data *data, int *len)
{
	wchar_t		*wstr;
	char		*str;

	wstr = va_arg(va, wchar_t *);
	if (wstr == 0)
	{
		*len = (data->precision != -1) ? ft_min(data->precision, 6) : 6;
		str = ft_strndup("(null)", *len);
	}
	else
	{
		if ((*len = get_byte_size(wstr, data)) == -2)
			return (0);
		str = fill_full_string(*len, wstr);
	}
	return (str);
}

int				process_special_string(va_list va, t_treat_data *data,
					t_string_buffer *sb)
{
	char		*str;
	char		*tmp;
	int			size_tot;

	if ((str = get_first_rep(va, data, &size_tot)) == 0)
		return (-2);
	if (data->gabarit > size_tot)
	{
		if (data->minus_flag)
		{
			tmp = ft_strsetnew(data->gabarit, ' ');
			ft_strncpy(tmp, str, size_tot);
		}
		else
		{
			tmp = ft_strsetnew(data->gabarit, data->zero_flag ? '0' : ' ');
			ft_strncpy(tmp + data->gabarit - size_tot, str, size_tot);
		}
		free(str);
		str = tmp;
		size_tot = data->gabarit;
	}
	sb_append_special(sb, str, size_tot);
	free(str);
	return (0);
}
