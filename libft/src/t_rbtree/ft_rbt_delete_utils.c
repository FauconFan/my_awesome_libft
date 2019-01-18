/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_delete_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:52:02 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:59:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					delete_case6(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	sibling = ft_rbt_node_sibling(n);
	sibling->color = ft_rbt_node_color(n->parent);
	n->parent->color = BLACK;
	if (n == n->parent->left)
	{
		sibling->right->color = BLACK;
		ft_rbt_rotate_left(t, n->parent);
	}
	else
	{
		sibling->left->color = BLACK;
		ft_rbt_rotate_right(t, n->parent);
	}
}

static void					delete_case5(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	if (n == n->parent->left &&
		(sibling = ft_rbt_node_sibling(n)) != NULL &&
		ft_rbt_node_color(sibling) == BLACK &&
		ft_rbt_node_color(sibling->left) == RED &&
		ft_rbt_node_color(sibling->right) == BLACK)
	{
		sibling->color = RED;
		sibling->left->color = BLACK;
		ft_rbt_rotate_right(t, sibling);
	}
	else if (n == n->parent->right &&
		(sibling = ft_rbt_node_sibling(n)) != NULL &&
		ft_rbt_node_color(sibling) == BLACK &&
		ft_rbt_node_color(sibling->right) == RED &&
		ft_rbt_node_color(sibling->left) == BLACK)
	{
		sibling->color = RED;
		sibling->right->color = BLACK;
		ft_rbt_rotate_left(t, sibling);
	}
	delete_case6(t, n);
}

static void					delete_case4(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	if (ft_rbt_node_color(n->parent) == RED &&
		(sibling = ft_rbt_node_sibling(n)) != NULL &&
		ft_rbt_node_color(sibling) == BLACK &&
		ft_rbt_node_color(sibling->left) == BLACK &&
		ft_rbt_node_color(sibling->right) == BLACK)
	{
		sibling->color = RED;
		n->parent->color = BLACK;
	}
	else
		delete_case5(t, n);
}

static void					delete_case3(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	if (ft_rbt_node_color(n->parent) == BLACK &&
		(sibling = ft_rbt_node_sibling(n)) != NULL &&
		ft_rbt_node_color(sibling) == BLACK &&
		ft_rbt_node_color(sibling->left) == BLACK &&
		ft_rbt_node_color(sibling->right) == BLACK)
	{
		sibling->color = RED;
		ft_delete_case_general(t, n->parent);
	}
	else
		delete_case4(t, n);
}

void						ft_delete_case_general(
								t_rbtree *t,
								t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	if (n->parent == NULL)
		return ;
	else
	{
		sibling = ft_rbt_node_sibling(n);
		if (ft_rbt_node_color(sibling) == RED)
		{
			n->parent->color = RED;
			sibling->color = BLACK;
			if (n == n->parent->left)
				ft_rbt_rotate_left(t, n->parent);
			else
				ft_rbt_rotate_right(t, n->parent);
		}
		delete_case3(t, n);
	}
}
