/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_iterparam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:44:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_slist_iterparam(
					t_slist *lst,
					void *param,
					void (*f)(void *content, void *param))
{
	t_slist_elem	*actu;

	actu = lst->head;
	while (actu)
	{
		f(actu->content, param);
		actu = actu->next;
	}
}
