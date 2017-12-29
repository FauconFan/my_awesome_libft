/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:21:50 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/29 18:25:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(void)
{
	char	**splited;

	splited = ft_strsplit("    coucoucou.  je.   mappelle.      ", ' ');
	if (ft_strcmp(splited[0], "coucoucou.") != 0 ||
		ft_strcmp(splited[1], "je.") != 0 ||
		ft_strcmp(splited[2], "mappelle.") != 0 ||
		splited[3] != 0)
		return (1);
	free(splited[0]);
	free(splited[1]);
	free(splited[2]);
	free(splited);
	return (0);
}
