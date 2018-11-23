#include "libft.h"

void		*ft_rbt_lookup(t_rbtree *t, void *key)
{
	t_rbtree_node	*n;

	n = ft_rbt_node_lookup(t, key);
	return ((n == NULL) ? NULL : n->value);
}
