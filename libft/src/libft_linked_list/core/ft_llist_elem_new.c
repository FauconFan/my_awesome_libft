/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_elem_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:19:44 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 16:47:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist_elem				*ft_llist_elem_new(void *content)
{
	t_llist_elem	*res;

	ft_memcheck((res = (t_llist_elem *)malloc(sizeof(t_llist_elem))));
	res->content = content;
	res->next = NULL;
	return (res);
}
