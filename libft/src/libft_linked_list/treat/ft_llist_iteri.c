/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_iteri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:30:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						ft_llist_iteri(
								t_llist *lst,
								void (*f)(void *, size_t))
{
	t_llist_elem	*actu;
	size_t			i;

	actu = lst->datas;
	i = 0;
	while (actu)
	{
		f(actu->content, i);
		actu = actu->next;
		i++;
	}
}
