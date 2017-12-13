/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_treat_data.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:07:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:36:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_VALUES_TREAT_DATA_H
# define SET_VALUES_TREAT_DATA_H

# include "libft.h"
# include "struct_treat_data.h"
# include "treat_data_utils.h"
# include "set_values_treat_data2.h"

char	*set_flags_treat_data(char *str, t_treat_data *data);
char	*set_gabarit_treat_data(char *str, t_treat_data *data, va_list va);
char	*set_precision_treat_data(char *str, t_treat_data *data, va_list va);
char	*set_length_modifer(char *str, t_treat_data *data);
char	*set_converter_treat_data(char *str, t_treat_data *data);

#endif
