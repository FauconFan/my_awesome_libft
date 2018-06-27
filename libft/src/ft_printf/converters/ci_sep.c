/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:56:49 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/26 14:25:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	process_sep(t_treat_data *data, t_string_buffer *sb)
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
		sb_append_special(sb, tmp, data->gabarit);
		free(tmp);
	}
	else
	{
		sb_append_special(sb, res, 1);
	}
}
