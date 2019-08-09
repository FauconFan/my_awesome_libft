/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:07 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:58:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					ft_rbt_delete_swap(t_rbtree_node **n_ptr)
{
	t_rbtree_node	*n;
	t_rbtree_node	*pred;
	void			*kv[2];

	n = *n_ptr;
	pred = n->left;
	while (pred->right)
		pred = pred->right;
	kv[0] = n->key;
	kv[1] = n->value;
	n->key = pred->key;
	n->value = pred->value;
	pred->key = kv[0];
	pred->value = kv[1];
	n = pred;
	*n_ptr = n;
}

void						ft_rbt_delete(t_rbtree *t, void *key)
{
	t_rbtree_node	*child;
	t_rbtree_node	*n;

	n = ft_rbt_node_lookup(t, key);
	if (n == NULL)
		return ;
	if (n->left != NULL && n->right != NULL)
		ft_rbt_delete_swap(&n);
	child = (n->right == NULL) ? n->left : n->right;
	if (ft_rbt_node_color(n) == BLACK)
	{
		n->color = ft_rbt_node_color(child);
		ft_delete_case_general(t, n);
	}
	ft_rbt_node_replace(t, n, child);
	if (n->parent == NULL && child != NULL)
		child->color = BLACK;
	ft_rbt_node_free_single(t, n);
}
