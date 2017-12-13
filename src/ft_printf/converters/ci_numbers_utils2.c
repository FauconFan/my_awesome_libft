/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 07:50:03 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/02 11:57:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_numbers_utils2.h"

char	*handle_negative_decimal_numbers(t_treat_data *data)
{
	if (data->plus_flag)
		return (ft_strndup(PLUS_SOLO, 1));
	else if (data->space_flag)
		return (ft_strndup(SPACE_SOLO, 1));
	return (ft_strnew(0));
}

char	*handle_hashtag_flag(char **str, t_treat_data *data)
{
	if (data->converter_id == CI_XMIN && data->precision != 0 &&
				ft_strcmp(*str, ZERO_SOLO) != 0)
		return (ft_strndup(PREFIX_XMIN, 2));
	else if (data->converter_id == CI_XMAJ && data->precision != 0 &&
				ft_strcmp(*str, ZERO_SOLO) != 0)
		return (ft_strndup(PREFIX_XMAJ, 2));
	else if (data->converter_id == CI_OMIN &&
					ft_strncmp(*str, ZERO_SOLO, 1) != 0)
		return (ft_strndup(ZERO_SOLO, 1));
	else if (data->converter_id == CI_P)
		return (ft_strndup(PREFIX_XMIN, 2));
	return (ft_strnew(0));
}
