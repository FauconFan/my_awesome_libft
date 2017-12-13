/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_ascii.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:29:03 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:36:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_STRING_ASCII_H
# define CI_STRING_ASCII_H

# include "libft.h"
# include "struct_treat_data.h"
# include "string_buffer.h"

void	process_normal_string(va_list va, t_treat_data *data,
				t_string_buffer *sb);
void	process_normal_char(va_list va, t_treat_data *res,
				t_string_buffer *sb);

#endif
