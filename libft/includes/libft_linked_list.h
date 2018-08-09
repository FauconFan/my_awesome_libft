/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_linked_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:22:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:47:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LINKED_LIST_H
#define LIBFT_LINKED_LIST_H

#include "libft.h"

typedef struct			s_llist_elem
{
	void				*content;
	struct s_llist_elem	*next;
}						t_llist_elem;

typedef struct			s_llist
{
	t_llist_elem		*datas;
	t_bool				copy_on_add;
	size_t				len;
	void				(*free)(void *);
	void				*(*cpy)(void *);
	int					(*cmp)(void *, void *);
}						t_llist;

/*
**	Core
*/

t_llist					*ft_llist_new(
									void (*free_f)(void *));

void					ft_llist_add_cpy(
									t_llist *lst,
									void *(*cpy_f)(void *),
									t_bool copy_on_add);

void					ft_llist_add_cmp(
									t_llist *lst,
									int (*cmp_f)(void *, void *));

void					ft_llist_free(t_llist **head);

t_llist_elem			*ft_llist_elem_new(void *content);

t_llist					*ft_llist_cpy(t_llist *lst);

/*
**	Modify
*/

void					ft_llist_addfront(t_llist *head, void *content);
void					ft_llist_addback(t_llist *head, void *content);

void					ft_llist_pop(t_llist *lst);
void					ft_llist_remove(t_llist *lst, size_t i);

t_bool					ft_llist_merge(t_llist *lst1, t_llist *lst2);
void					ft_llist_merge_one(t_llist *lst, void *data);

void					ft_llist_sort(t_llist *lst);

void					ft_llist_rev(t_llist *lst);

/*
**	Static
*/

size_t					ft_llist_size(t_llist *lst);
t_bool					ft_llist_isempty(t_llist *lst);

void					*ft_llist_head(t_llist *lst);
void					*ft_llist_last(t_llist *lst);
void					*ft_llist_get(t_llist *lst, size_t i);

/*
**	Treat
*/

void					ft_llist_iter(
									t_llist *lst,
									void (*f)(void *));

void					ft_llist_iteri(
									t_llist *lst,
									void (*f)(void *, size_t));

void					ft_llist_iterparam(
									t_llist *lst,
									void *param,
									void (*f)(void *, void *));

void					ft_llist_iteriparam(
									t_llist *lst,
									void *param,
									void (*f)(void *, void *, size_t));

void					ft_llist_iterparam2(
									t_llist *lst,
									void *param1,
									void *param2,
									void (*f)(void *, void *, void *));

void					ft_llist_iteriparam2(
									t_llist *lst,
									void *param1,
									void *param2,
									void (*f)(void *, void *, void *, size_t));

t_llist					*ft_llist_map(
									t_llist *lst,
									void *(*f)(void *),
									void (*free_f)(void *));

void					*ft_llist_find(
									t_llist *lst,
									size_t	*rank,
									t_bool (*f)(void *));

void					*ft_llist_findparam(
									t_llist *lst,
									size_t	*rank,
									void *param,
									t_bool (*f)(void *content, void *param));

#endif
