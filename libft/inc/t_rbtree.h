/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rbtree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:01:34 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:54:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RBTREE_H
# define T_RBTREE_H

typedef enum				e_rbtree_color
{
	RED,
	BLACK,
}							t_rbtree_color;

typedef struct				s_rbtree_node
{
	void					*key;
	void					*value;
	struct s_rbtree_node	*left;
	struct s_rbtree_node	*right;
	struct s_rbtree_node	*parent;
	t_rbtree_color			color;
}							t_rbtree_node;

typedef struct				s_rbtree
{
	t_rbtree_node			*root;
	int						(*comp_f)(void *, void *);
	void					(*free_key)(void *);
	void					(*free_value)(void *);
}							t_rbtree;

t_rbtree					*ft_rbt_init(
								int (*comp_f)(void *, void *),
								void (*free_key)(void *),
								void (*free_value)(void *));

void						ft_rbt_free(
								t_rbtree *t);

void						ft_rbt_insert(
								t_rbtree *t,
								void *key,
								void *value);

void						ft_insert_case_general(
								t_rbtree *t,
								t_rbtree_node *n);

void						ft_rbt_delete(
								t_rbtree *t,
								void *key);

void						ft_delete_case_general(
								t_rbtree *t,
								t_rbtree_node *n);

void						*ft_rbt_lookup(
								t_rbtree *t,
								void *key);

t_rbtree_node				*ft_rbt_node_grandparent(
								t_rbtree_node *n);

t_rbtree_node				*ft_rbt_node_sibling(
								t_rbtree_node *n);

t_rbtree_node				*ft_rbt_node_uncle(
								t_rbtree_node *n);

t_rbtree_color				ft_rbt_node_color(
								t_rbtree_node *n);

void						ft_rbt_node_free_single(
								t_rbtree *t,
								t_rbtree_node *n);

t_rbtree_node				*ft_rbt_node_init(
								void *key,
								void *value);

t_rbtree_node				*ft_rbt_node_lookup(
								t_rbtree *t,
								void *key);

void						ft_rbt_node_replace(
								t_rbtree *t,
								t_rbtree_node *oldn,
								t_rbtree_node *newn);

void						ft_rbt_rotate_left(
								t_rbtree *t,
								t_rbtree_node *n);

void						ft_rbt_rotate_right(
								t_rbtree *t,
								t_rbtree_node *n);

#endif
