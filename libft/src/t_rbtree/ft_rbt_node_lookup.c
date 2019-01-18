/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_node_lookup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:28 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:18:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rbtree_node	*ft_rbt_node_lookup(t_rbtree *t, void *key)
{
	t_rbtree_node	*n;
	int				comp_ret;

	n = t->root;
	while (n != NULL)
	{
		comp_ret = (t->comp_f)(key, n->key);
		if (comp_ret == 0)
			return (n);
		else if (comp_ret < 0)
			n = n->left;
		else
			n = n->right;
	}
	return (n);
}
