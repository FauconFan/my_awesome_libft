/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:09:09 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:43:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

void			*ft_slist_head(t_slist *lst)
{
	if (lst->head == NULL)
		return (NULL);
	return (lst->head->content);
}
