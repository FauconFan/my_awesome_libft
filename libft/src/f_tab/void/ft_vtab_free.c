/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtab_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:01:32 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 10:46:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_vtab_free(void ***tab_ptr)
{
	void	**tab;
	size_t	i;

	if (tab_ptr == NULL || *tab_ptr == NULL)
		return ;
	tab = *tab_ptr;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	*tab_ptr = NULL;
}
