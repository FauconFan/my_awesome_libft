/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:32 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:18:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_rbt_rotate_left(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*r;

	r = n->right;
	ft_rbt_node_replace(t, n, r);
	n->right = r->left;
	if (r->left != NULL)
		r->left->parent = n;
	r->left = n;
	n->parent = r;
}

void		ft_rbt_rotate_right(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*l;

	l = n->left;
	ft_rbt_node_replace(t, n, l);
	n->left = l->right;
	if (l->right != NULL)
		l->right->parent = n;
	l->right = n;
	n->parent = l;
}
