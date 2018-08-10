/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtab_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:13:42 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 08:53:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_vtab_delete(void ***tab_ptr, size_t i)
{
	void	**tab;
	size_t	len;

	tab = *tab_ptr;
	len = ft_vtab_len(tab);
	if (i >= len)
		return ;
	free(tab[i]);
	while (i < len - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = NULL;
}
