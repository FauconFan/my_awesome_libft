/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:34 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:18:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbtree_node	*ft_rbt_node_grandparent(t_rbtree_node *n)
{
	return (n->parent->parent);
}

t_rbtree_node	*ft_rbt_node_sibling(t_rbtree_node *n)
{
	if (n == n->parent->left)
		return (n->parent->right);
	return (n->parent->left);
}

t_rbtree_node	*ft_rbt_node_uncle(t_rbtree_node *n)
{
	return (ft_rbt_node_sibling(n->parent));
}

t_rbtree_color	ft_rbt_node_color(t_rbtree_node *n)
{
	return ((n == NULL) ? BLACK : n->color);
}
