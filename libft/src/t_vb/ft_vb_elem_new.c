/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vb_elem_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 08:30:37 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/30 08:34:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_void_buffer	*ft_vb_elem_new(void *buffer, size_t len)
{
	t_void_buffer	*elem;

	ft_memcheck((elem = (t_void_buffer *)malloc(sizeof(t_void_buffer))));
	elem->buffer = buffer;
	elem->len = len;
	return (elem);
}
