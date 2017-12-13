/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:45:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 15:51:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *alst)
{
	int		res;

	res = 1;
	if (alst == 0)
		return (0);
	while (alst->next != 0)
	{
		alst = alst->next;
		res++;
	}
	return (res);
}
