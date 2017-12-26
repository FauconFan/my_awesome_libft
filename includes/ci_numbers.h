/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:19 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 08:18:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_NUMBERS_H
# define CI_NUMBERS_H

# include "libft.h"
# include "includes/struct_treat_data.h"
# include "includes/ft_lltoa_n_ulltoa.h"
# include "includes/ci_numbers_utils.h"
# include "includes/string_buffer.h"

void				process_numbers(va_list va, t_treat_data *data,
						t_string_buffer *sb);

#endif
