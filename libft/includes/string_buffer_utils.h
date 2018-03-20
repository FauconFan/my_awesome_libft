/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:42 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:34:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BUFFER_UTILS_H
# define STRING_BUFFER_UTILS_H

# include "libft.h"

void		free_string_buffer(
		t_string_buffer *res);
void		free_last(t_string_buffer *res);

#endif
