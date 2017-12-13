/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_unicode_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:58:42 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/03 12:25:47 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_string_unicode.h"

int		get_byte_size(wchar_t *wstr, t_treat_data *data)
{
	int	res;
	int	index;
	int	prec_actu;

	res = 0;
	index = 0;
	prec_actu = 0;
	while (wstr[index])
	{
		prec_actu = ft_wcharlen(wstr[index]);
		if (prec_actu > (int)MB_CUR_MAX)
			return (-2);
		if (data->precision != -1 && res + prec_actu > data->precision)
			break ;
		res += prec_actu;
		index++;
	}
	index++;
	while (wstr[index])
	{
		if (ft_wcharlen(wstr[index]) > (int)MB_CUR_MAX)
			return (-2);
		index++;
	}
	return (res);
}

char	*fill_full_string(int max, wchar_t *wstr)
{
	char	*str;
	int		index;
	int		bytes_cara;
	int		bytes_tot_cara;

	index = 0;
	bytes_cara = 0;
	bytes_tot_cara = 0;
	str = ft_strnew(max);
	while (wstr[index])
	{
		bytes_cara = ft_wcharlen(wstr[index]);
		if (bytes_tot_cara + bytes_cara > max)
			break ;
		fill_string(wstr[index], str + bytes_tot_cara, bytes_cara);
		bytes_tot_cara += bytes_cara;
		index++;
	}
	return (str);
}
