/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vb_elem_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 08:30:37 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 12:13:14 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structvb.h"
#include "libft_memory.h"

t_void_buffer	*ft_vb_elem_new(void *buffer, size_t len)
{
	t_void_buffer	*elem;

	ft_memcheck((elem = (t_void_buffer *)malloc(sizeof(t_void_buffer))));
	ft_memcheck((elem->buffer = malloc(len)));
	ft_memcpy(elem->buffer, buffer, len);
	elem->len = len;
	return (elem);
}
