/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:41:48 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/14 18:32:35 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctestcom.h"

char	*get_file_content(char *path)
{
	char				*res;
	struct stat			statbuffer;
	int					fd;
	int					ret;

	if ((lstat(path, &statbuffer)) == -1 || (fd = open(path, O_RDONLY)) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit(1);
	}
	res = tct_strnew(statbuffer.st_size);
	if ((ret = read(fd, res, statbuffer.st_size)) == -1 || close(fd) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit(1);
	}
	res[ret] = '\0';
	return (res);
}
