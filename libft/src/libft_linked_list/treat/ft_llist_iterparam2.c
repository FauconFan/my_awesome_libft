/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_iterparam2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:32:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_iterparam2(
								t_llist *lst,
								void *param1,
								void *param2,
								void (*f)(void *, void *, void *))
{
	t_llist_elem	*actu;

	actu = lst->datas;
	while (actu)
	{
		f(actu->content, param1, param2);
		actu = actu->next;
	}
}
