/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_findparam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:53:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 18:06:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

void			*ft_slist_findparam(
						t_slist *lst,
						size_t *rank,
						void *param,
						t_bool (*f)(void *content, void *param))
{
	t_slist_elem	*actu;
	size_t			i;

	actu = lst->head;
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
