/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:53:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 18:06:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_slist_find(
						t_slist *lst,
						size_t *rank,
						t_bool (*f)(void *content))
{
	t_slist_elem	*actu;
	size_t			i;

	actu = lst->head;
	i = 0;
	while (actu)
	{
		if (f(actu->content))
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
