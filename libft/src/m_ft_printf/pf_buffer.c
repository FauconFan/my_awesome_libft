/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:23:46 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:00:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_pf_buffer_content	*ft_create_pf_content(char *str, int byte_stored)
{
	t_pf_buffer_content	*res;

	ft_memcheck((res = (t_pf_buffer_content *)malloc(sizeof(t_pf_buffer_content))));
	res->str = ft_strdup(str);
	res->byte_stored = byte_stored;
	return res;
}

static void					ft_free_pf_content(t_pf_buffer_content *bf)
{
	free(bf->str);
	free(bf);
}

t_pf_buffer					*ft_create_pf_buffer()
{
	t_slist		*res;

	res = ft_slist_new(MAKE_FREE_PTR(ft_free_pf_content));
	return res;
}

void						pf_append(t_pf_buffer *pf, char *str)
{
	pf_append_special(pf, str, ft_strlen(str));
}

void						pf_append_special(t_pf_buffer *pf, char *str, int size)
{
	ft_slist_addfront(pf, ft_create_pf_content(str, size));
}
