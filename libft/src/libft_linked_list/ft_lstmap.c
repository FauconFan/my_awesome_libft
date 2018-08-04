/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:29:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 15:17:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *content))
{
	t_list	*res;

	res = 0;
	if (lst != 0)
	{
		res = ft_lstnew(f(lst->content));
		res->next = ft_lstmap(lst->next, f);
	}
	return (res);
}
