/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_node_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:23 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:18:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbtree_node		*ft_rbt_node_init(void *key, void *value)
{
	t_rbtree_node	*node;

	ft_memcheck((node = (t_rbtree_node *)malloc(sizeof(t_rbtree_node))));
	node->color = RED;
	node->key = key;
	node->value = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
