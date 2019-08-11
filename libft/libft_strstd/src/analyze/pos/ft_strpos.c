/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:43:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/07 14:58:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

int		ft_strpos(char *big, char *little)
{
	int		index[2];

	if (ft_strlen(big) < ft_strlen(little))
		return (-1);
	else if (ft_strlen(big) == ft_strlen(little))
		return ((ft_strcmp(big, little)) == 0 ? 0 : -1);
	index[0] = 0;
	index[1] = 0;
	while (big[index[0]])
	{
		if (big[index[0]] == *little)
		{
			index[1] = 0;
			while (big[index[0] + index[1]] != 0 && little[index[1]] != 0 &&
						big[index[0] + index[1]] == little[index[1]])
			{
				index[1]++;
			}
			if (little[index[1]] == 0)
				return (index[0]);
		}
		index[0]++;
	}
	return (-1);
}
