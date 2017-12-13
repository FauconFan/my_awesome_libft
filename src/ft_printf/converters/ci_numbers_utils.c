/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:17:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/02 11:54:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ci_numbers_utils.h"

static long long			get_rep_no_unsigned(va_list va, t_treat_data *data)
{
	if (data->length_modifier_id != -1)
	{
		if (data->length_modifier_id == LM_HH)
			return ((long long)((char)va_arg(va, int)));
		else if (data->length_modifier_id == LM_H)
			return ((long long)((short)va_arg(va, int)));
		else if (data->length_modifier_id == LM_L)
			return ((long long)va_arg(va, long));
		else if (data->length_modifier_id == LM_LL)
			return ((long long)va_arg(va, long long));
		else if (data->length_modifier_id == LM_J)
			return ((long long)va_arg(va, intmax_t));
		else if (data->length_modifier_id == LM_Z)
			return ((long long)va_arg(va, size_t));
	}
	if (data->converter_id == CI_DMIN || data->converter_id == CI_I)
		return ((long long)va_arg(va, int));
	return ((long long)va_arg(va, long int));
}

static unsigned long long	get_rep_unsigned(va_list va, t_treat_data *data)
{
	if (data->length_modifier_id != -1)
	{
		if (data->length_modifier_id == LM_HH)
			return ((unsigned long long)
				((unsigned char)va_arg(va, unsigned int)));
		else if (data->length_modifier_id == LM_H)
			return ((unsigned long long)
				((unsigned short)va_arg(va, unsigned int)));
		else if (data->length_modifier_id == LM_L)
			return ((unsigned long long)va_arg(va, unsigned long));
		else if (data->length_modifier_id == LM_LL)
			return ((unsigned long long)va_arg(va, unsigned long long));
		else if (data->length_modifier_id == LM_J)
			return ((unsigned long long)va_arg(va, uintmax_t));
		else if (data->length_modifier_id == LM_Z)
			return ((unsigned long long)va_arg(va, size_t));
	}
	return ((unsigned long long)va_arg(va, unsigned int));
}

static char					*get_first_rep_ci_numbers(
								va_list va, t_treat_data *res)
{
	if (res->converter_id == CI_DMIN || res->converter_id == CI_I)
		return (ft_lltoa_base(get_rep_no_unsigned(va, res), BASE_DECA));
	else if (res->converter_id == CI_OMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), BASE_OCTO));
	else if (res->converter_id == CI_UMIN)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), BASE_DECA));
	else if (res->converter_id == CI_XMIN || res->converter_id == CI_P)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), BASE_HEXAMIN));
	else if (res->converter_id == CI_XMAJ)
		return (ft_ulltoa_base(get_rep_unsigned(va, res), BASE_HEXAMAJ));
	return (ft_strnew(0));
}

char						*get_rep_with_prec(va_list va, t_treat_data *data)
{
	char	*str;
	char	*tmp;
	int		is_negative;

	str = get_first_rep_ci_numbers(va, data);
	is_negative = (*str == '-');
	if (data->precision + (*str == '-') > (int)ft_strlen(str))
	{
		tmp = ft_strsetnew(data->precision + is_negative, '0');
		ft_strncpy(tmp + data->precision + 2 * is_negative - ft_strlen(str),
			str + is_negative,
			ft_strlen(str) - is_negative);
		if (is_negative)
			*tmp = '-';
		free(str);
		str = tmp;
	}
	else if (data->precision == 0 && ft_strcmp(ZERO_SOLO, str) == 0)
	{
		free(str);
		str = ft_strnew(0);
	}
	return (str);
}

char						*get_prefix(char **str, t_treat_data *data)
{
	char	*tmp;

	if (**str == '-')
	{
		tmp = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		free(*str);
		*str = tmp;
		return (ft_strndup(MINUS_SOLO, 1));
	}
	else if (**str != '-' && (data->converter_id == CI_DMIN ||
			data->converter_id == CI_I))
		return (handle_negative_decimal_numbers(data));
	else if (data->hashtag_flag)
		return (handle_hashtag_flag(str, data));
	return (ft_strnew(0));
}
