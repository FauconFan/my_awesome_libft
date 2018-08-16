/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:25:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/16 09:01:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_all_content(char *file_path, char **errno_str)
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
		fd = open(file_path, O_RDONLY);
		content_file = ft_strnew(stat_actu.st_size);
		read(fd, content_file, stat_actu.st_size);
		close(fd);
	}
	else
	{
		*errno_str = strerror(errno);
	}
	return (content_file);
}
