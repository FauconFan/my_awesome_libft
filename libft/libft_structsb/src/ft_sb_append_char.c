/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb_append_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:03:52 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 12:07:44 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structsb.h"
#include "libft_strstd.h"

void		ft_sb_append_char(t_sb *sb, char c, size_t len)
{
	char	*str;

	str = ft_strsetnew(len, c);
	ft_sb_append(sb, str);
	free(str);
}
