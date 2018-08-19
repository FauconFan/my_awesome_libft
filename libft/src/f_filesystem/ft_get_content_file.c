/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:25:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 16:15:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_content_file(char *file_path, char **errno_str)
{
	int				fd;
	int				ret;
	struct stat		stat_actu;
	char			*content_file;

	*errno_str = NULL;
	content_file = NULL;
	ret = stat(file_path, &stat_actu);
	if (ret == 0)
	{
		if ((fd = open(file_path, O_RDONLY)) < 0)
			*errno_str = strerror(errno);
		else
		{
			content_file = ft_strnew(stat_actu.st_size);
			if (read(fd, content_file, stat_actu.st_size) < 0)
				*errno_str = strerror(errno);
			else
			{
				if (close(fd) < 0)
					*errno_str = strerror(errno);
			}
		}
	}
	else
	{
		*errno_str = strerror(errno);
	}
	return (content_file);
}
