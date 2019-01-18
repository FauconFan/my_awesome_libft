/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:19 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:50:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rbt_build_in_place(
					t_rbtree *t,
					t_rbtree_node *n,
					void *key,
					void *value)
{
	if (t->free_key)
		(t->free_key)(key);
	if (t->free_value)
		(t->free_value)(n->value);
	n->value = value;
}

static int		ft_rbt_utils_left(
					t_rbtree_node **n,
					t_rbtree_node **cand,
					void *key,
					void *value)
{
	if ((*n)->left == NULL)
	{
		*cand = ft_rbt_node_init(key, value);
		(*n)->left = *cand;
		return (1);
	}
	*n = (*n)->left;
	return (0);
}

static int		ft_rbt_utils_right(
					t_rbtree_node **n,
					t_rbtree_node **cand,
					void *key,
					void *value)
{
	if ((*n)->right == NULL)
	{
		*cand = ft_rbt_node_init(key, value);
		(*n)->right = *cand;
		return (1);
	}
	*n = (*n)->right;
	return (0);
}

static int		ft_rbt_parcours(
					t_rbtree *t,
					t_rbtree_node **cand,
					void *key,
					void *value)
{
	t_rbtree_node	*n;
	int				comp_res;
	int				ret;

	n = t->root;
	while (1)
	{
		comp_res = (t->comp_f)(key, n->key);
		if (comp_res == 0)
		{
			ft_rbt_build_in_place(t, n, key, value);
			return (1);
		}
		else
		{
			if (comp_res < 0)
				ret = ft_rbt_utils_left(&n, cand, key, value);
			else
				ret = ft_rbt_utils_right(&n, cand, key, value);
			if (ret)
				break ;
		}
	}
	(*cand)->parent = n;
	return (0);
}

/*
**	Return if the cand node has beed used in the tree.
**	I.E. if the value is not in the set.
*/

void			ft_rbt_insert(
					t_rbtree *t,
					void *key,
					void *value)
{
	t_rbtree_node	*cand;

	if (t->root == NULL)
	{
		cand = ft_rbt_node_init(key, value);
		t->root = cand;
	}
	else
	{
		if (ft_rbt_parcours(t, &cand, key, value))
			return ;
	}
	ft_insert_case_general(t, cand);
}
