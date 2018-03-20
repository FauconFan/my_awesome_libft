/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:29:35 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/10 17:49:13 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *content))
{
	t_list	*res;

	res = 0;
	if (lst != 0)
	{
		res = ft_lstnew_nocpy(f(lst->content));
		res->next = ft_lstmap(lst->next, f);
	}
	return (res);
}

t_list	*ft_lstmapparam(t_list *lst, void *param,
			void *(*f)(void *content, void *param))
{
	t_list	*res;

	res = 0;
	if (lst != 0)
	{
		res = ft_lstnew_nocpy(f(lst->content, param));
		res->next = ft_lstmapparam(lst->next, param, f);
	}
	return (res);
}
