/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:36:29 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 20:24:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	f(char *s)
{
	ft_putendl(s);
}

void	pprint(char **s)
{
	ft_stab_iter(s, f);
}

int		main(void)
{
	char	**tab;

	tab = ft_stab_new(2, "cool");
	ft_stab_insert(&tab, 2, "wow");
	ft_stab_push(&tab, "begin");
	ft_stab_append(&tab, "end");
	ft_stab_delete(&tab, 2);
	ft_stab_push(&tab, "to delete");
	ft_stab_pop(&tab);
	pprint(tab);
	ft_putnbrl(ft_stab_len(tab));
	ft_stab_free(&tab);
	return 0;
}
