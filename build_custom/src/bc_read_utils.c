/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_read_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:35:39 by pepe              #+#    #+#             */
/*   Updated: 2017/12/16 22:56:46 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

int		open_read_file(char *name_file, unsigned int size_tot, char **str_tot)
{
	int		fd;
	int		ret;

	if ((fd = open(name_file, O_RDONLY)) == -1)
	{
		dprintf(2, "name_file is not valid\n");
		exit(1);
	}
	if ((ret = read(fd, *str_tot, size_tot)) == -1)
		exit(1);
	(*str_tot)[ret] = 0;
	return (fd);
}
