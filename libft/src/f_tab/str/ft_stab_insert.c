/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:12:25 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 08:36:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_stab_insert(char ***tab_ptr, size_t index, char *s)
{
	ft_vtab_insert((void ***)tab_ptr, index, (void *)s, ft_strlen(s));
}
