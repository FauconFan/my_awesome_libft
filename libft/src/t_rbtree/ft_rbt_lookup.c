/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbt_lookup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:18:21 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:18:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_rbt_lookup(t_rbtree *t, void *key)
{
	t_rbtree_node	*n;

	n = ft_rbt_node_lookup(t, key);
	return ((n == NULL) ? NULL : n->value);
}
