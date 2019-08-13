/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 21:59:53 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:35:53 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

static const char	*ft_strrchr_recu(const char *s, int c, const char *res_actu)
{
	if (*s == 0)
		return ((c == '\0') ? s : res_actu);
	if (*s == c)
		return (ft_strrchr_recu(s + 1, c, s));
	return (ft_strrchr_recu(s + 1, c, res_actu));
}

const char			*ft_strrchr(const char *s, int c)
{
	return (ft_strrchr_recu(s, c, NULL));
}
