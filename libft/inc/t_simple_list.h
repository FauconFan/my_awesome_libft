/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_simple_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:22:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 08:10:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SIMPLE_LIST_H
#define T_SIMPLE_LIST_H

#include "libft.h"

typedef struct			s_slist_elem
{
	void				*content;
	struct s_slist_elem	*next;
}						t_slist_elem;

typedef struct			s_slist
{
	t_slist_elem		*head;
	t_bool				copy_on_add;
	size_t				len;
	void				(*free)(void *);
	void				*(*cpy)(void *);
	int					(*cmp)(void *, void *);
}						t_slist;

/*
**	Core
*/

t_slist					*ft_slist_new(
									void (*free_f)(void *));

void					ft_slist_add_cpy(
									t_slist *lst,
									void *(*cpy_f)(void *),
									t_bool copy_on_add);

void					ft_slist_add_cmp(
									t_slist *lst,
									int (*cmp_f)(void *, void *));

void					ft_slist_free(t_slist **head);

t_slist_elem			*ft_slist_elem_new(void *content);

t_slist					*ft_slist_cpy(t_slist *lst);

/*
**	Modify
*/

void					ft_slist_addfront(t_slist *head, void *content);
void					ft_slist_addback(t_slist *head, void *content);

void					ft_slist_pop(t_slist *lst);
void					ft_slist_remove(t_slist *lst, size_t i);

t_bool					ft_slist_merge(t_slist *lst1, t_slist *lst2);
void					ft_slist_merge_one(t_slist *lst, void *data);

void					ft_slist_sort(t_slist *lst);

void					ft_slist_rev(t_slist *lst);

/*
**	Static
*/

size_t					ft_slist_size(t_slist *lst);
t_bool					ft_slist_isempty(t_slist *lst);

void					*ft_slist_head(t_slist *lst);
void					*ft_slist_last(t_slist *lst);
void					*ft_slist_get(t_slist *lst, size_t i);

/*
**	Treat
*/

void					ft_slist_iter(
									t_slist *lst,
									void (*f)(void *));

void					ft_slist_iteri(
									t_slist *lst,
									void (*f)(void *, size_t));

void					ft_slist_iterparam(
									t_slist *lst,
									void *param,
									void (*f)(void *, void *));

void					ft_slist_iteriparam(
									t_slist *lst,
									void *param,
									void (*f)(void *, void *, size_t));

void					ft_slist_iterparam2(
									t_slist *lst,
									void *param1,
									void *param2,
									void (*f)(void *, void *, void *));

void					ft_slist_iteriparam2(
									t_slist *lst,
									void *param1,
									void *param2,
									void (*f)(void *, void *, void *, size_t));

t_slist					*ft_slist_map(
									t_slist *lst,
									void *(*f)(void *),
									void (*free_f)(void *));

void					*ft_slist_find(
									t_slist *lst,
									size_t	*rank,
									t_bool (*f)(void *));

void					*ft_slist_findparam(
									t_slist *lst,
									size_t	*rank,
									void *param,
									t_bool (*f)(void *content, void *param));

#endif
