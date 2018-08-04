/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_lstiterparam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 17:32:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_iterparam(t_llist *lst, void *param,
							void (*f)(void *content, void *param))
{
	t_llist_elem	*actu;

	actu = lst->datas;
	while (actu)
	{
		f(actu->content, param);
		actu = actu->next;
	}
}
