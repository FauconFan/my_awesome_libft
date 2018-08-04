/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:45:20 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 18:09:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_llist_size(t_llist const *alst)
{
	size_t			res;
	t_llist_elem	*actu;

	res = 1;
	if (alst == 0)
		return (0);
	actu = alst->datas;
	if (actu == NULL)
		return 0;
	while (actu->next)
	{
		actu = actu->next;
		res++;
	}
	return (res);
}
