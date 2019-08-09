/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:56:49 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 09:28:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	process_sep(t_treat_data *data, t_pf_buffer *pf)
{
	char	*res;
	char	*tmp;

	res = "%";
	if (data->gabarit > 1)
	{
		tmp = ft_strsetnew(data->gabarit,
			(data->zero_flag && data->minus_flag == 0) ? '0' : ' ');
		if (data->minus_flag)
			ft_strncpy(tmp, res, 1);
		else
			ft_strncpy(tmp + data->gabarit - 1, res, 1);
		pf_append_special(pf, tmp, data->gabarit);
		free(tmp);
	}
	else
	{
		pf_append_special(pf, res, 1);
	}
}
