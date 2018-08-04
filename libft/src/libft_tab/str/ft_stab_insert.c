/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:12:25 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 20:00:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_stab_insert(char ***tab_ptr, size_t index, char *s)
{
	char	**tmp;
	size_t	len;
	size_t	i;

	if (tab_ptr == NULL)
		return ;
	len = ft_stab_len(*tab_ptr);
	i = 0;
	if (index > len)
		index = len;
	ft_memcheck((tmp = (char **)malloc(sizeof(char *) * (len + 2))));
	while (i < index)
	{
		tmp[i] = (*tab_ptr)[i];
		i++;
	}
	tmp[i++] = ft_strdup(s);
	while (i < len + 1)
	{
		tmp[i] = (*tab_ptr)[i - 1];
		i++;
	}
	tmp[i] = NULL;
	free(*tab_ptr);
	*tab_ptr = tmp;
}
