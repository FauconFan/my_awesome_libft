/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb_tostring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:01:08 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 12:26:11 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structsb.h"
#include "libft_strstd.h"

static void					calculate_length(void *elem, void *param)
{
	char					*str;
	size_t					*size;

	str = (char *)elem;
	size = (size_t *)param;
	*size = *size + ft_strlen(str);
}

static void					build_str(void *elem, void *param1, void *param2)
{
	char					*str;
	size_t					*actu;
	char					**res;
	size_t					len;

	str = (char *)elem;
	actu = (size_t *)param1;
	res = (char **)param2;
	len = ft_strlen(str);
	ft_strncpy(*res + *actu - len, str, len);
	*actu = *actu - len;
}

char						*ft_sb_tostring(t_sb *sb)
{
	char	*res;
	size_t	len_tot_stored;

	len_tot_stored = 0;
	ft_slist_iterparam(sb, &len_tot_stored, calculate_length);
	res = ft_strnew(len_tot_stored);
	ft_slist_iterparam2(sb, &len_tot_stored, &res, build_str);
	return (res);
}
