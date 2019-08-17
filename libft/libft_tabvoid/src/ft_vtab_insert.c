/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtab_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:12:25 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/16 00:32:22 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabvoid.h"
#include "libft_memory.h"

void		ft_vtab_insert(void ***tab_ptr, size_t index, void *s, size_t len_s)
{
	void	**tmp;
	size_t	len;
	size_t	i;

	if (tab_ptr == NULL)
		return ;
	len = ft_vtab_len(*tab_ptr);
	i = (size_t)-1;
	if (index > len)
		index = len;
	ft_memcheck((tmp = (void **)malloc(sizeof(void *) * (len + 2))));
	while (++i < index)
		tmp[i] = (*tab_ptr)[i];
	ft_memcheck((tmp[i] = ft_memalloc(len_s + 1)));
	ft_memcpy(tmp[i], s, len_s);
	while (++i < len + 1)
		tmp[i] = (*tab_ptr)[i - 1];
	tmp[i] = NULL;
	free(*tab_ptr);
	*tab_ptr = tmp;
}
