/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_elem_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:19:44 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:57:02 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"
#include "libft_memory.h"

t_slist_elem				*ft_slist_elem_new(void *content)
{
	t_slist_elem	*res;

	ft_memcheck((res = (t_slist_elem *)malloc(sizeof(t_slist_elem))));
	res->content = content;
	res->next = NULL;
	return (res);
}
