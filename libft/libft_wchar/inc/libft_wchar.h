/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_wchar.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 00:01:05 by pepe              #+#    #+#             */
/*   Updated: 2019/08/16 00:05:57 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_WCHAR_H
# define LIBFT_WCHAR_H

# include <wchar.h>

int		ft_wcharlen(wchar_t wchar);
void	ft_fill_wstring_len(wchar_t wchar, char *str, int size);
void	ft_fill_wstring(wchar_t wchar, char *str);

#endif
