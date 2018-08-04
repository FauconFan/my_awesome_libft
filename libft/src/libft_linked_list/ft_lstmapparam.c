/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:29:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 15:17:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmapparam(t_list *lst, void *param,
			void *(*f)(void *content, void *param))
{
	t_list	*res;

	res = 0;
	if (lst != 0)
	{
		res = ft_lstnew(f(lst->content, param));
		res->next = ft_lstmapparam(lst->next, param, f);
	}
	return (res);
}
