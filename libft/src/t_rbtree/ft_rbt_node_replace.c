#include "libft.h"

void		ft_rbt_node_replace(t_rbtree *t, t_rbtree_node *oldn, t_rbtree_node *newn)
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
