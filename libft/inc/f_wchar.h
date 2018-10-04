/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_wchar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:19:04 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 11:59:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_WCHAR_H
# define F_WCHAR_H

# include "libft.h"

int		ft_wcharlen(wchar_t wchar);
void	ft_fill_wstring_len(wchar_t wchar, char *str, int size);
void	ft_fill_wstring(wchar_t wchar, char *str);

#endif
