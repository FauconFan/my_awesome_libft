/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_linked_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:22:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/27 08:23:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LINKED_LIST_H
#define LIBFT_LINKED_LIST_H

#include "libft.h"

typedef struct	s_list
{
	void				*content;
	struct s_list		*next;
}				t_list;

t_list			*ft_lstnew(void *content, void *(*cpy)(void *));
t_list			*ft_lstnew_nocpy(void *content);

void			ft_lstfreeall(t_list **head,
							void (*free_elem)(void *content));
void			ft_lstaddfront(t_list **head, void *content,
							void *(*cpy)(void *data));
void			ft_lstaddfront_nocpy(t_list **head, void *content);
void			ft_lstaddback(t_list **head, void *content,
							void *(*cpy)(void *data));
void			ft_lstaddback_nocpy(t_list **head, void *content);
int				ft_lstsize(t_list *alst);
void			ft_lstiter(t_list *lst, void (*f)(void *content));
void			ft_lstiterparam(t_list *lst, void *param,
					void (*f)(void *content, void *param));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *content));
t_list			*ft_lstmapparam(t_list *lst, void *param,
					void *(*f)(void *content, void *param));
void			ft_lstmerge(
						t_list **head,
						void *data,
						int (*cmp)(void *d1, void *d2),
						void *(*cpy)(void *data));
void			ft_lstmerge_nocpy(
						t_list **head,
						void *data,
						int (*cmp)(void *d1, void *d2));

#endif
