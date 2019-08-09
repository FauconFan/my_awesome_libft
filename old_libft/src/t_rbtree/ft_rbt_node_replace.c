/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_node_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:30 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:18:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_rbt_node_replace(
				t_rbtree *t,
				t_rbtree_node *oldn,
				t_rbtree_node *newn)
{
	if (oldn->parent == NULL)
		t->root = newn;
	else
	{
		if (oldn == oldn->parent->left)
			oldn->parent->left = newn;
		else
			oldn->parent->right = newn;
	}
	if (newn != NULL)
		newn->parent = oldn->parent;
}
