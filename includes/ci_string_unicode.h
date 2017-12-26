/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_string_unicode.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:32:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 08:19:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_STRING_UNICODE_H
# define CI_STRING_UNICODE_H

# include "libft.h"
# include "includes/struct_treat_data.h"
# include "includes/string_buffer.h"

int		process_special_char(va_list va, t_treat_data *data,
					t_string_buffer *sb);
int		process_special_string(va_list va, t_treat_data *data,
					t_string_buffer *sb);

int		ft_wcharlen(wchar_t wchar);
void	fill_string(wchar_t wchar, char *str, int size);
int		get_byte_size(wchar_t *wstr, t_treat_data *data);
char	*fill_full_string(int max, wchar_t *wstr);

#endif
