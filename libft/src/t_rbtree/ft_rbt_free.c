#include "libft.h"
#include <stdio.h>

static void			node_free(t_rbtree *t, t_rbtree_node *n)
{
	if (n != NULL)
	{
		node_free(t, n->left);
		node_free(t, n->right);
		ft_rbt_node_free_single(t, n);
	}
}

void				ft_rbt_node_free_single(t_rbtree *t, t_rbtree_node *n)
{
	if (t->free_value)
		(t->free_value)(n->value);
	if (t->free_key)
		(t->free_key)(n->key);
}

void				ft_rbt_free(t_rbtree *t)
{
	node_free(t, t->root);
	free(t);
}
