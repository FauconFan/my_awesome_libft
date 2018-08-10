/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:28:12 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 09:26:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	process_normal_string(va_list va, t_treat_data *data,
			t_pf_buffer *pf)
{
	char	*res;
	char	*tmp;

	res = va_arg(va, char *);
	res = (res == 0) ? "(null)" : res;
	if (data->precision != -1 && data->precision < (int)ft_strlen(res))
	{
		res = ft_strndup(res, data->precision);
	}
	if (data->gabarit > (int)ft_strlen(res))
	{
		tmp = ft_strsetnew(data->gabarit,
			(data->zero_flag && data->minus_flag == 0) ? '0' : ' ');
		if (data->minus_flag)
			ft_strncpy(tmp, res, ft_strlen(res));
		else
			ft_strncpy(tmp + data->gabarit - ft_strlen(res),
				res, ft_strlen(res));
		pf_append_special(pf, tmp, data->gabarit);
		free(tmp);
	}
	else
		pf_append(pf, res);
}

void	process_normal_char(va_list va, t_treat_data *data, t_pf_buffer *pf)
{
	char	*str;
	char	c;
	int		len;

	len = ft_max(1, data->gabarit);
	str = ft_strsetnew(len, (data->zero_flag) ? '0' : ' ');
	c = (char)va_arg(va, int);
	if (data->minus_flag)
		*str = c;
	else
		str[len - 1] = c;
	pf_append_special(pf, str, len);
	free(str);
}
