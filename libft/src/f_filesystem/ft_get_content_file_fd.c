/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content_file_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:25:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/09/20 09:10:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_content_file_fd(
				int fd,
				size_t *size_file,
				char **errno_str)
{
	int				ret;
	struct stat		stat_actu;
	char			*content_file;

	*errno_str = NULL;
	content_file = NULL;
	ret = fstat(fd, &stat_actu);
	if (ret == 0)
	{
		content_file = ft_strnew(stat_actu.st_size);
		if (read(fd, content_file, stat_actu.st_size) < 0)
		{
			*errno_str = strerror(errno);
		}
		*size_file = stat_actu.st_size;
	}
	else
	{
		*errno_str = strerror(errno);
	}
	return (content_file);
}
