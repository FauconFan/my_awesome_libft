/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vb_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 08:44:45 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 15:13:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void                           ft_vb_append(t_vb *vb, void *buff, size_t len)
{
       t_void_buffer   *buffer;

       buffer = ft_vb_elem_new(buff, len);
       ft_slist_push(vb, buffer);
}
