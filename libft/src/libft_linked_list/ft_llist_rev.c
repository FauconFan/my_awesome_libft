/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:08:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 16:36:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *content, void *param)
{
	t_llist		*res;

	res = (t_llist *)param;
	ft_llist_addfront(res, res->cpy(content));
}

t_llist			*ft_llist_rev(t_llist *lst)
{
	t_llist		*res;

	res = ft_llist_new(lst->free, lst->cpy);
	ft_llist_iterparam(lst, res, f);
	return res;
}
