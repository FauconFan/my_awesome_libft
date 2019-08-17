/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_iteri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:44:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

void						ft_slist_iteri(
								t_slist *lst,
								void (*f)(void *, size_t))
{
	t_slist_elem	*actu;
	size_t			i;

	actu = lst->head;
	i = 0;
	while (actu)
	{
		f(actu->content, i);
		actu = actu->next;
		i++;
	}
}
