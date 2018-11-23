#include "libft.h"

static t_rbtree_node		*maximum_node(t_rbtree_node *n);
static void					delete_case1(t_rbtree *t, t_rbtree_node *n);
static void					delete_case2(t_rbtree *t, t_rbtree_node *n);
static void					delete_case3(t_rbtree *t, t_rbtree_node *n);
static void					delete_case4(t_rbtree *t, t_rbtree_node *n);
static void					delete_case5(t_rbtree *t, t_rbtree_node *n);
static void					delete_case6(t_rbtree *t, t_rbtree_node *n);

void						ft_rbt_delete(t_rbtree *t, void *key)
{
	t_rbtree_node	*child;
	t_rbtree_node	*n;
	t_rbtree_node	*pred;
	void			*kv[2];

	n = ft_rbt_node_lookup(t, key);
	if (n == NULL)
		return ;
	if (n->left != NULL && n->right != NULL)
	{
		pred = maximum_node(n->left);
		kv[0] = n->key;
		kv[1] = n->value;
		n->key = pred->key;
		n->value = pred->value;
		pred->key = kv[0];
		pred->value = kv[1];
		n = pred;
	}
	child = (n->right == NULL) ? n->left : n->right;
	if (ft_rbt_node_color(n) == BLACK)
	{
		n->color = ft_rbt_node_color(child);
		delete_case1(t, n);
	}
	ft_rbt_node_replace(t, n, child);
	if (n->parent == NULL && child != NULL)
		child->color = BLACK;
	ft_rbt_node_free_single(t, n);
}

static t_rbtree_node		*maximum_node(t_rbtree_node *n)
{
	while (n->right != NULL)
		n = n->right;
	return (n);
}

static void					delete_case1(t_rbtree *t, t_rbtree_node *n)
{
	if (n->parent == NULL)
		return ;
	else
		delete_case2(t, n);
}

static void					delete_case2(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	sibling = ft_rbt_node_sibling(n);
	if (ft_rbt_node_color(sibling) == RED)
	{
		n->parent->color = RED;
		sibling->color = BLACK;
		if (n == n->parent->left)
			ft_rbt_rotate_left(t, n->parent);
		else
			ft_rbt_rotate_right(t, n->parent);
	}
	delete_case3(t, n);
}

static void					delete_case3(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	if (ft_rbt_node_color(n->parent) == BLACK &&
		(sibling = ft_rbt_node_sibling(n)) != NULL &&
		ft_rbt_node_color(sibling) == BLACK &&
		ft_rbt_node_color(sibling->left) == BLACK &&
		ft_rbt_node_color(sibling->right) == BLACK)
	{
		sibling->color = RED;
		delete_case1(t, n->parent);
	}
	else
		delete_case4(t, n);
}

static void					delete_case4(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	if (ft_rbt_node_color(n->parent) == RED &&
		(sibling = ft_rbt_node_sibling(n)) != NULL &&
		ft_rbt_node_color(sibling) == BLACK &&
		ft_rbt_node_color(sibling->left) == BLACK &&
		ft_rbt_node_color(sibling->right) == BLACK)
	{
		sibling->color = RED;
		n->parent->color = BLACK;
	}
	else
		delete_case5(t, n);
}

static void					delete_case5(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	if (n == n->parent->left &&
		(sibling = ft_rbt_node_sibling(n)) != NULL &&
		ft_rbt_node_color(sibling) == BLACK &&
		ft_rbt_node_color(sibling->left) == RED &&
		ft_rbt_node_color(sibling->right) == BLACK)
	{
		sibling->color = RED;
		sibling->left->color = BLACK;
		ft_rbt_rotate_right(t, sibling);
	}
	else if (n == n->parent->right &&
		(sibling = ft_rbt_node_sibling(n)) != NULL &&
		ft_rbt_node_color(sibling) == BLACK &&
		ft_rbt_node_color(sibling->right) == RED &&
		ft_rbt_node_color(sibling->left) == BLACK)
	{
		sibling->color = RED;
		sibling->right->color = BLACK;
		ft_rbt_rotate_left(t, sibling);
	}
	delete_case6(t, n);
}

static void					delete_case6(t_rbtree *t, t_rbtree_node *n)
{
	t_rbtree_node	*sibling;

	sibling = ft_rbt_node_sibling(n);
	sibling->color = ft_rbt_node_color(n->parent);
	n->parent->color = BLACK;
	if (n == n->parent->left)
	{
		sibling->right->color = BLACK;
		ft_rbt_rotate_left(t, n->parent);
	}
	else
	{
		sibling->left->color = BLACK;
		ft_rbt_rotate_right(t, n->parent);
	}
}
