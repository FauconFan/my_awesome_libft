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
