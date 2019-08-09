/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_unused_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:37:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 09:28:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	process_unused_flag(t_treat_data *data, t_pf_buffer *pf)
{
	char	*first_rep;
	char	*res;

	first_rep = "";
	if (data->converter_id == CI_Z)
		first_rep = "Z";
	else if (data->converter_id == CI_R)
		first_rep = "R";
	if (data->gabarit > 1)
	{
		if (data->minus_flag)
		{
			res = ft_strsetnew(data->gabarit, ' ');
			ft_strncpy(res, first_rep, 1);
		}
		else
		{
			res = ft_strsetnew(data->gabarit, data->zero_flag ? '0' : ' ');
			ft_strncpy(res + data->gabarit - 1, first_rep, 1);
		}
		pf_append_special(pf, res, data->gabarit);
		free(res);
	}
	else
		pf_append(pf, first_rep);
}
