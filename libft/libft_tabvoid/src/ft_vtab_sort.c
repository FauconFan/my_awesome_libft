/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtab_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:33:12 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/16 00:33:05 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabvoid.h"

void		ft_vtab_sort(void **tab, int (*f)(void *, void *))
{
	size_t		len;
	size_t		i;
	size_t		j;
	size_t		rank;
	void		*min;

	len = ft_vtab_len(tab);
	i = (size_t)-1;
	min = NULL;
	while (++i < len - 1)
	{
		rank = i;
		min = tab[rank];
		j = i;
		while (++j < len)
		{
			if (f(min, tab[j]) > 0)
			{
				rank = j;
				min = tab[rank];
			}
		}
		tab[rank] = tab[i];
		tab[i] = min;
	}
}
