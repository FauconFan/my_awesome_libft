/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_treat_data2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:16:19 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/16 16:02:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		set_converter_treat_data2(char cpy)
{
	if (cpy == 'S')
		return (CI_SMAJ);
	else if (cpy == 'D')
		return (CI_DMAJ);
	else if (cpy == 'O')
		return (CI_OMAJ);
	else if (cpy == 'U')
		return (CI_UMAJ);
	else if (cpy == 'X')
		return (CI_XMAJ);
	else if (cpy == 'C')
		return (CI_CMAJ);
	else if (cpy == 'E')
		return (CI_EMAJ);
	else if (cpy == 'F')
		return (CI_FMAJ);
	else if (cpy == 'G')
		return (CI_GMAJ);
	else if (cpy == 'A')
		return (CI_AMAJ);
	else if (cpy == 'B')
		return (CI_BMAJ);
	return (-1);
}

void	update_uppercase_for_l_lm(char letter, t_treat_data *data)
{
	if (letter == 'D' || letter == 'O' || letter == 'U')
	{
		data->length_modifier_id = LM_L;
		data->converter_id = data->converter_id - 1;
	}
	else if (letter == 'p')
	{
		data->length_modifier_id = LM_LL;
		data->hashtag_flag = 1;
	}
	else if (letter == 'c' && data->length_modifier_id == LM_L)
	{
		data->converter_id = CI_CMAJ;
		data->length_modifier_id = -1;
	}
	else if (letter == 's' && data->length_modifier_id == LM_L)
	{
		data->converter_id = CI_SMAJ;
		data->length_modifier_id = -1;
	}
}
