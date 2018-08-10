/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_add_cpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:36:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 13:38:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_slist_add_cpy(
									t_slist *lst,
									void *(*cpy_f)(void *),
									t_bool copy_on_add)
{
	lst->cpy = cpy_f;
	lst->copy_on_add = copy_on_add;
}
