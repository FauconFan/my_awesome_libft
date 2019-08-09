/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb_append_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:03:52 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 13:04:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sb_append_char(t_sb *sb, char c, size_t len)
{
	char	*str;

	str = ft_strsetnew(len, c);
	ft_sb_append(sb, str);
	ft_strdel(&str);
}
