/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_findparam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:53:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 11:07:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_llist_findparam(
						t_llist *lst,
						void *param,
						t_bool (*f)(void *content, void *param))
{
	t_llist_elem	*actu;

	actu = lst->datas;
	while (actu)
	{
		if (f(actu->content, param))
			return (actu->content);
		actu = actu->next;
	}
	return (NULL);
}
