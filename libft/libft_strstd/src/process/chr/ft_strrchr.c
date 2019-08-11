/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 21:59:53 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:54:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

static char	*ft_strrchr_recu(const char *s, int c, const char *res_actu)
{
	if (*s == 0)
		return ((c == '\0') ? (char *)s : (char *)res_actu);
	if (*s == c)
		return (ft_strrchr_recu(s + 1, c, s));
	return (ft_strrchr_recu(s + 1, c, res_actu));
}

char		*ft_strrchr(const char *s, int c)
{
	return (ft_strrchr_recu(s, c, NULL));
}
