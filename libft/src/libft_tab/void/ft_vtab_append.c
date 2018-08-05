/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtab_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:06:19 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 08:38:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_vtab_append(void ***tab_ptr, void *s, size_t len_s)
{
	ft_vtab_insert(tab_ptr, ft_vtab_len(*tab_ptr), s, len_s);
}
