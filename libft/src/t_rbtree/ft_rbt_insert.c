#include "libft.h"

static void		insert_case1(t_rbtree *t, t_rbtree_node *n);
static void		insert_case2(t_rbtree *t, t_rbtree_node *n);
static void		insert_case3(t_rbtree *t, t_rbtree_node *n);
static void		insert_case4(t_rbtree *t, t_rbtree_node *n);
static void		insert_case5(t_rbtree *t, t_rbtree_node *n);

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
	t_rbtree_node	*n;
	int				comp_res;

	if (t->root == NULL)
	{
		cand = ft_rbt_node_init(key, value);
		t->root = cand;
	}
	else
	{
		n = t->root;
		while (1)
		{
			comp_res = (t->comp_f)(key, n->key);
			if (comp_res == 0)
			{
				if (t->free_key)
					(t->free_key)(key);
				if (t->free_value)
					(t->free_value)(n->value);
				n->value = value;
				return ;
			}
			else if (comp_res < 0)
			{
				if (n->left == NULL)
				{
					cand = ft_rbt_node_init(key, value);
					n->left = cand;
					break;
				}
				else
					n = n->left;
			}
			else
			{
				if (n->right == NULL)
				{
					cand = ft_rbt_node_init(key, value);
					n->right = cand;
					break;
				}
				else
					n = n->right;
			}
		}
		cand->parent = n;
	}
	insert_case1(t, cand);
}

static void		insert_case1(t_rbtree *t, t_rbtree_node *n)
{
	if (n->parent == NULL)
		n->color = BLACK;
	else
		insert_case2(t, n);
}

static void		insert_case2(t_rbtree *t, t_rbtree_node *n)
{
	if (ft_rbt_node_color(n->parent) == BLACK)
		return ;
	else
		insert_case3(t, n);
}

static void		insert_case3(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*uncle;
	t_rbtree_node	*grandpa;

	uncle = ft_rbt_node_uncle(n);
	if (ft_rbt_node_color(uncle) == RED)
	{
		grandpa = ft_rbt_node_grandparent(n);
		n->parent->color = BLACK;
		uncle->color = BLACK;
		grandpa->color = RED;
		insert_case1(t, grandpa);
	}
	else
		insert_case4(t, n);
}

static void		insert_case4(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*grandpa;

	grandpa = ft_rbt_node_grandparent(n);
	if (n == n->parent->right && n->parent == grandpa->left)
	{
		ft_rbt_rotate_left(t, n->parent);
		n = n->left;
	}
	else if (n == n->parent->left && n->parent == grandpa->right)
	{
		ft_rbt_rotate_right(t, n->parent);
		n = n->right;
	}
	insert_case5(t, n);
}

static void		insert_case5(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*grandpa;

	grandpa = ft_rbt_node_grandparent(n);
	n->parent->color = BLACK;
	grandpa->color = RED;
	if (n == n->parent->left && n->parent == grandpa->left)
		ft_rbt_rotate_right(t, grandpa);
	else
		ft_rbt_rotate_left(t, grandpa);
}
