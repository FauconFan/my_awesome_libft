/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_helper_properly.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 12:54:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 13:05:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		build_helper_properly2(t_sb *sb, char **tab, int l, int r)
{
	int		len;
	int		rank;
	int		actu;

	len = 0;
	rank = 0;
	while (tab[rank] && (len + (int)ft_strlen(tab[rank]) < r - 1))
	{
		len += ft_strlen(tab[rank]) + (len != 0);
		rank++;
	}
	actu = 0;
	while (actu < rank)
	{
		if (actu != 0)
			ft_sb_append(sb, " ");
		ft_sb_append(sb, tab[actu]);
		actu++;
	}
	if (tab[rank])
	{
		ft_sb_append(sb, "\n");
		actu = 0;
		ft_sb_append_char(sb, ' ', l);
		build_helper_properly2(sb, tab + rank, l, r);
	}
}

char	*build_helper_properly(char *helper, int l, int r)
{
	t_sb	*sb;
	char	**tab;
	char	*res;

	sb = ft_sb_new();
	tab = ft_strsplit(helper, ' ');
	build_helper_properly2(sb, tab, l, r);
	res = ft_sb_tostring(sb);
	ft_sb_free(&sb);
	ft_stab_free(&tab);
	return res;
}
