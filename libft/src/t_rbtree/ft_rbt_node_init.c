#include "libft.h"

t_rbtree_node		*ft_rbt_node_init(void *key, void *value)
{
	t_rbtree_node	*node;

	ft_memcheck((node = (t_rbtree_node *)malloc(sizeof(t_rbtree_node))));
	node->color = RED;
	node->key = key;
	node->value = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
