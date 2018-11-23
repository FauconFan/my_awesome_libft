#include "libft.h"

t_rbtree	*ft_rbt_init(
			int (*comp_f)(void *, void *),
			void (*free_key)(void *),
			void (*free_value)(void *))
{
	t_rbtree	*rb;

	if ((rb = (t_rbtree *)malloc(sizeof(t_rbtree))) == NULL)
		exit (2); // FIXME
	rb->root = NULL;
	rb->comp_f = comp_f;
	rb->free_key = free_key;
	rb->free_value = free_value;
	return (rb);
}
