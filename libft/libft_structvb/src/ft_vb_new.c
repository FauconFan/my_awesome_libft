/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vb_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 08:29:03 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/30 08:44:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structvb.h"

t_vb				*ft_vb_new(void)
{
	t_vb			*res;

	res = ft_slist_new(MAKE_FREE_PTR(ft_vb_elem_free));
	return (res);
}
