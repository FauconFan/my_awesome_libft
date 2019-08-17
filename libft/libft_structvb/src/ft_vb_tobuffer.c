/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vb_tobuffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 08:47:01 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 12:14:04 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structvb.h"
#include "libft_memory.h"

static void			calculate_length(void *elem, void *param)
{
	t_void_buffer		*buffer;
	size_t				*size;

	buffer = (t_void_buffer *)elem;
	size = (size_t *)param;
	*size = *size + buffer->len;
}

static void			build_str(void *elem, void *param1, void *param2)
{
	t_void_buffer		*buffer;
	size_t				*actu;
	char				**res;

	buffer = (t_void_buffer *)elem;
	actu = (size_t *)param1;
	res = (char **)param2;
	ft_memcpy(*res + *actu - buffer->len, buffer->buffer, buffer->len);
	*actu = *actu - buffer->len;
}

void				*ft_vb_tobuffer(t_vb *vb)
{
	void		*res;
	size_t		len_tot_stored;

	len_tot_stored = 0;
	ft_slist_iterparam(vb, &len_tot_stored, calculate_length);
	ft_memcheck((res = ft_memalloc(len_tot_stored)));
	ft_slist_iterparam2(vb, &len_tot_stored, &res, build_str);
	return (res);
}
