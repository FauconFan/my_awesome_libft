/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:16 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:18:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbtree	*ft_rbt_init(
			int (*comp_f)(void *, void *),
			void (*free_key)(void *),
			void (*free_value)(void *))
{
	t_rbtree	*rb;

	ft_memcheck((rb = (t_rbtree *)malloc(sizeof(t_rbtree))));
	rb->root = NULL;
	rb->comp_f = comp_f;
	rb->free_key = free_key;
	rb->free_value = free_value;
	return (rb);
}
