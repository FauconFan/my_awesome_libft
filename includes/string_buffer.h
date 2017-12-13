/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:24:08 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:35:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BUFFER_H
# define STRING_BUFFER_H

# include "libft.h"

typedef struct				s_string_buffer
{
	char					*str;
	int						byte_stored;
	struct s_string_buffer	*next;
}							t_string_buffer;

t_string_buffer				*new_string_buffer_special(
		char *str,
		int byte_stored);

t_string_buffer				*new_string_buffer_normal(
		char *str);

void						sb_append_normal(
		t_string_buffer *head,
		char *str);

void						sb_append_special(
		t_string_buffer *head,
		char *str,
		int byte_stored);

int							build_str(
		t_string_buffer *head,
		char **res);

#endif
