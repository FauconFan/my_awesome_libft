/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:56:30 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 19:46:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_stab_new(size_t len, char *def)
{
	char	**res;
	size_t	i;

	ft_memcheck((res = (char **)malloc(sizeof(char *) * (len + 1))));
	i = 0;
	while (i < len)
	{
		res[i] = ft_strdup(def);
		i++;
	}
	res[len] = NULL;
	return res;
}
