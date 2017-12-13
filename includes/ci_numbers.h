/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:36:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_NUMBERS_H
# define CI_NUMBERS_H

# include "libft.h"
# include "struct_treat_data.h"
# include "ft_lltoa_n_ulltoa.h"
# include "ci_numbers_utils.h"
# include "string_buffer.h"

void				process_numbers(va_list va, t_treat_data *data,
						t_string_buffer *sb);

#endif
