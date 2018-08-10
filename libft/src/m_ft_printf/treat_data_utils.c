/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:49:36 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 09:20:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		init_treat_data(t_treat_data **data)
{
	if ((*data = (t_treat_data *)malloc(sizeof(t_treat_data))) == 0)
		return (0);
	(*data)->hashtag_flag = 0;
	(*data)->zero_flag = 0;
	(*data)->minus_flag = 0;
	(*data)->plus_flag = 0;
	(*data)->space_flag = 0;
	(*data)->gabarit = -1;
	(*data)->precision = -1;
	(*data)->length_modifier_id = -1;
	(*data)->converter_id = -1;
	return (1);
}

static char		*init_and_set_values_treat_data(char *str,
			t_treat_data **data, va_list va)
{
	char	*cpy;
	int		first_time;

	if (init_treat_data(data) == 0)
		return (0);
	first_time = 1;
	while (first_time == 1 || cpy != str)
	{
		first_time = 0;
		cpy = str;
		str = set_flags_treat_data(str, *data);
		str = set_gabarit_treat_data(str, *data, va);
		str = set_precision_treat_data(str, *data, va);
		str = set_length_modifer(str, *data);
	}
	str = set_converter_treat_data(str, *data);
	if (str == 0)
		free(*data);
	return (str);
}

static int		treat_data(t_treat_data *data, va_list va, t_pf_buffer *pf)
{
	if (data->converter_id == -1 ||
		(data->converter_id >= 24 && data->converter_id <= 32))
		return (0);
	if (data->converter_id == CI_CMIN)
		process_normal_char(va, data, pf);
	else if (data->converter_id == CI_SMIN)
		process_normal_string(va, data, pf);
	else if (data->converter_id == CI_CMAJ)
		return (process_special_char(va, data, pf));
	else if (data->converter_id == CI_SMAJ)
		return (process_special_string(va, data, pf));
	else if (data->converter_id == CI_SEP)
		process_sep(data, pf);
	else if (data->converter_id == CI_Z || data->converter_id == CI_R)
		process_unused_flag(data, pf);
	else if (data->converter_id >= 12 && data->converter_id <= 21)
		process_numbers(va, data, pf);
	else
	{
		ft_putstr_fd("should never happen", 2);
		return (2);
	}
	return (0);
}

static int		treat_sep(char **str, va_list va, t_pf_buffer *pf)
{
	t_treat_data	*data;

	if ((*str = init_and_set_values_treat_data(++(*str), &data, va)) == 0)
		return (-1);
	if (treat_data(data, va, pf) == -2)
	{
		free(data);
		return (-2);
	}
	free(data);
	return (0);
}

int				process(char *str, va_list va, t_pf_buffer *pf)
{
	char				*tmp;
	int					pos_first_percent;
	int					ret;

	while ((pos_first_percent = ft_strcpos(str, SEPERATOR)) != -1)
	{
		if ((tmp = ft_strsub(str, 0, pos_first_percent)) == 0)
			return (-1);
		pf_append(pf, tmp);
		str += pos_first_percent;
		free(tmp);
		if ((ret = treat_sep(&str, va, pf)) == -1)
			return (-1);
		if (ret == -2)
			return (-2);
	}
	pf_append(pf, str);
	return (0);
}
