/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:56:30 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 14:06:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_stab_new(size_t len, char *def)
{
	size_t	len_def;

	if (def == NULL || *def == '\0')
		len_def = 0;
	else
		len_def = ft_strlen(def);
	return ((char **)ft_vtab_new(len, def, len_def));
}
