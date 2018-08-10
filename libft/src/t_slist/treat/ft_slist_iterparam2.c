/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_iterparam2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:44:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_slist_iterparam2(
								t_slist *lst,
								void *param1,
								void *param2,
								void (*f)(void *, void *, void *))
{
	t_slist_elem	*actu;

	actu = lst->head;
	while (actu)
	{
		f(actu->content, param1, param2);
		actu = actu->next;
	}
}
