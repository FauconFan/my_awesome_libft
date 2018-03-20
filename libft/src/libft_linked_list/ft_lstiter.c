/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:26:21 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/10 17:49:05 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *content))
{
	if (lst != NULL)
	{
		f(lst->content);
		ft_lstiter(lst->next, f);
	}
}

void	ft_lstiterparam(t_list *lst, void *param,
			void (*f)(void *content, void *param))
{
	if (lst != NULL)
	{
		f(lst->content, param);
		ft_lstiterparam(lst->next, param, f);
	}
}
