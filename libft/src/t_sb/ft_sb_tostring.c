/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb_tostring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:01:08 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 11:14:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					calculate_length(void *elem, void *param)
{
	char					*str;
	int						*size;

	str = (char *)elem;
	size = (int *)param;
	*size = *size + ft_strlen(str);
}

static void					build_str(void *elem, void *param1, void *param2)
{
	char					*str;
	int						*actu;
	char					**res;
	size_t					len;

	str = (char *)elem;
	actu = (int *)param1;
	res = (char **)param2;
	len = ft_strlen(str);
	ft_strncpy(*res + *actu - len, str, len);
	*actu = *actu - len;
}

char						*ft_sb_tostring(t_sb *sb)
{
	char	*res;
	int		len_tot_stored;

	len_tot_stored = 0;
	ft_slist_iterparam(sb, &len_tot_stored, calculate_length);
	res = ft_strnew(len_tot_stored);
	ft_slist_iterparam2(sb, &len_tot_stored, &res, build_str);
	return res;
}
