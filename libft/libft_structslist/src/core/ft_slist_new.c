/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:35:52 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:57:36 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"
#include "libft_memory.h"

t_slist					*ft_slist_new(void (*free_f)(void *elem))
{
	t_slist		*res;

	ft_memcheck((res = (t_slist *)malloc(sizeof(t_slist))));
	res->head = NULL;
	res->len = 0;
	res->free = free_f;
	res->cpy = NULL;
	res->cmp = NULL;
	return (res);
}
