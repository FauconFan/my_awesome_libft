/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtab_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:56:30 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/15 13:45:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_vtab_new(size_t len, void *def, size_t len_def)
{
	void	**res;
	size_t	i;

	ft_memcheck((res = (void **)malloc(sizeof(void *) * (len + 1))));
	i = 0;
	if (def == NULL)
	{
		while (i < len)
		{
			res[i] = NULL;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			ft_memcheck((res[i] = ft_memalloc(len_def + 1)));
			ft_memcpy(res[i], def, len_def);
			i++;
		}
	}
	res[len] = NULL;
	return (res);
}
