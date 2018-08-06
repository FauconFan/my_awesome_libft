/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_linked_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:22:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 10:58:16 by jpriou           ###   ########.fr       */
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
	void				(*free)(void *content);
	int					(*cmp)(void *d1, void *d2);
}						t_llist;

t_llist					*ft_llist_new(
									void (*free_f)(void *elem),
									int (*cmp_f)(void *d1, void *d2));
void					ft_llist_free(t_llist **head);

t_llist_elem			*ft_llist_elem_new(void *content);

void					ft_llist_addfront(t_llist *head, void *content);
void					ft_llist_addback(t_llist *head, void *content);

size_t					ft_llist_size(t_llist const *alst);

void					ft_llist_iter(t_llist *lst, void (*f)(void *content));
void					ft_llist_iterparam(t_llist *lst, void *param,
									void (*f)(void *content, void *param));
void					ft_llist_iterparam2(t_llist *lst, void *param1, void *param2,
									void (*f)(void *content, void *p1, void *p2));
t_llist					*ft_llist_map(t_llist *lst,
									void *(*f)(void *content),
									void (*free_f)(void *elem),
									int (*cmp_f)(void *d1, void *d2));

void					*ft_llist_find(
									t_llist *lst,
									t_bool (*f)(void *content));
void					*ft_llist_findparam(
									t_llist *lst,
									void *param,
									t_bool (*f)(void *content, void *param));

void					ft_llist_merge(t_llist *lst, void *data);

#endif
