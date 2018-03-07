/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:20:17 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/07 13:46:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctestcom.h"

void	ft_printusage(void)
{
	dprintf(2, "./ctestcom PATH_ORIGIN PATH_TARGET\n");
}

/*
** Testcom :
**	printf("coucou\n");
**	printf("ceci est le menu !\n");
**	assert(0);
**	assert(1);
*/

int		main(int argc, char **argv)
{
	t_ctestcom	*ctestcom;

	if (argc != 3)
	{
		ft_printusage();
		exit (1);
	}
	ctestcom = init_ctestcom(argv[1], argv[2]);
	tct_parser(ctestcom);
	tct_addcontext(ctestcom);
	dprintf(ctestcom->fd_target, "%s", ctestcom->generate_string);
	free_ctestcom(&ctestcom);
	return (0);
}
