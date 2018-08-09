/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_iteriparam2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:31:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_iteriparam2(
				t_llist *lst,
				void *param1,
				void *param2,
				void (*f)(void *, void *, void *, size_t))
{
	t_llist_elem	*actu;
	size_t			i;

	actu = lst->datas;
	i = 0;
	while (actu)
	{
		f(actu->content, param1, param2, i);
		actu = actu->next;
		i++;
	}
}
