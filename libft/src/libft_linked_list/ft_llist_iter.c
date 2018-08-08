/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/08 15:21:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						ft_llist_iter(t_llist *lst, void (*f)(void *content))
{
	t_llist_elem	*actu;

	actu = lst->datas;
	while (actu)
	{
		f(actu->content);
		actu = actu->next;
	}
}
