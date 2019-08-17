/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:44:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

void						ft_slist_iter(
								t_slist *lst,
								void (*f)(void *content))
{
	t_slist_elem	*actu;

	actu = lst->head;
	while (actu)
	{
		f(actu->content);
		actu = actu->next;
	}
}
