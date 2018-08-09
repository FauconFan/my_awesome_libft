/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_findparam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:53:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:39:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_llist_findparam(
						t_llist *lst,
						size_t	*rank,
						void *param,
						t_bool (*f)(void *content, void *param))
{
	t_llist_elem	*actu;
	size_t			i;

	actu = lst->datas;
	i = 0;
	while (actu)
	{
		if (f(actu->content, param))
		{
			if (rank != NULL)
				*rank = i;
			return (actu->content);
		}
		actu = actu->next;
		i++;
	}
	if (rank != NULL)
		*rank = 0;
	return (NULL);
}
