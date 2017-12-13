/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcrpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:42:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:52:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcrpos_recu(char *s, int c, int res_actu, int nb_cara_actu)
{
	if (*s == 0)
		return (res_actu);
	if (*s == c)
		return (ft_strcrpos_recu(s + 1, c, nb_cara_actu, nb_cara_actu + 1));
	return (ft_strcrpos_recu(s + 1, c, res_actu, nb_cara_actu + 1));
}

int			ft_strcrpos(char *s, int c)
{
	return (ft_strcrpos_recu(s, c, -1, 0));
}
