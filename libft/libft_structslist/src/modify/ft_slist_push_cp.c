/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_push_cp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:22:05 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 11:34:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

void	ft_slist_push_cp(t_slist *head, void *content)
{
	ft_slist_addfront(head, content, TRUE);
}
