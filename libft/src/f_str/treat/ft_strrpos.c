/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:54:17 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/07 14:57:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strrpos_recu
	(char *big, char *little, int res_actu, int nbcara_actu)
{
	int		index;

	index = 0;
	if (*big == 0)
		return (res_actu);
	if (*big == *little)
	{
		while (big[index] != 0 && little[index] != 0 &&
					big[index] == little[index])
		{
			index++;
		}
		if (little[index] == 0)
			return (
				ft_strrpos_recu(big + 1, little, nbcara_actu, nbcara_actu + 1));
	}
	return (ft_strrpos_recu(big + 1, little, res_actu, nbcara_actu + 1));
}

int				ft_strrpos(char *big, char *little)
{
	if (ft_strlen(big) < ft_strlen(little))
		return (-1);
	else if (ft_strlen(big) == ft_strlen(little))
		return ((ft_strcmp(big, little)) == 0 ? 0 : -1);
	return (ft_strrpos_recu(big, little, -1, 0));
}
