/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_insert_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:21:07 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:51:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		insert_case5(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*grandpa;

	grandpa = ft_rbt_node_grandparent(n);
	n->parent->color = BLACK;
	grandpa->color = RED;
	if (n == n->parent->left && n->parent == grandpa->left)
		ft_rbt_rotate_right(t, grandpa);
	else
		ft_rbt_rotate_left(t, grandpa);
}

static void		insert_case4(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*grandpa;

	grandpa = ft_rbt_node_grandparent(n);
	if (n == n->parent->right && n->parent == grandpa->left)
	{
		ft_rbt_rotate_left(t, n->parent);
		n = n->left;
	}
	else if (n == n->parent->left && n->parent == grandpa->right)
	{
		ft_rbt_rotate_right(t, n->parent);
		n = n->right;
	}
	insert_case5(t, n);
}

static void		insert_case3(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*uncle;
	t_rbtree_node	*grandpa;

	uncle = ft_rbt_node_uncle(n);
	if (ft_rbt_node_color(uncle) == RED)
	{
		grandpa = ft_rbt_node_grandparent(n);
		n->parent->color = BLACK;
		uncle->color = BLACK;
		grandpa->color = RED;
		ft_insert_case_general(t, grandpa);
	}
	else
		insert_case4(t, n);
}

static void		insert_case2(t_rbtree *t, t_rbtree_node *n)
{
	if (ft_rbt_node_color(n->parent) == BLACK)
		return ;
	else
		insert_case3(t, n);
}

void			ft_insert_case_general(t_rbtree *t, t_rbtree_node *n)
{
	if (n->parent == NULL)
		n->color = BLACK;
	else
		insert_case2(t, n);
}
