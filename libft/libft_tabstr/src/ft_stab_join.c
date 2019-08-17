/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:31:26 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:01:23 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_strstd.h"

static void		fill_content(
					char *res,
					char *joiner,
					char **tab,
					size_t size_tab)
{
	size_t	index_tab;
	size_t	tmp;
	size_t	index;

	index_tab = 0;
	index = 0;
	while (index_tab < size_tab - 1)
	{
		tmp = ft_strlen(tab[index_tab]);
		ft_strncpy(res + index, tab[index_tab], tmp);
		index += tmp;
		tmp = ft_strlen(joiner);
		ft_strncpy(res + index, joiner, tmp);
		index += tmp;
		index_tab++;
	}
	ft_strcpy(res + index, tab[index_tab]);
}

char			*ft_stab_join(char **tab, char *joiner)
{
	size_t	size_tot;
	size_t	size_tab;
	size_t	index_tab;
	char	*res;

	size_tot = 0;
	size_tab = ft_stab_len(tab);
	index_tab = 0;
	if (size_tab == 0)
		return (ft_strnew(0));
	while (index_tab < size_tab)
	{
		size_tot += ft_strlen(tab[index_tab]);
		index_tab++;
	}
	size_tot += (ft_strlen(joiner) * (size_tab - 1));
	res = ft_strnew(size_tot);
	fill_content(res, joiner, tab, size_tab);
	return (res);
}
