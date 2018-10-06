/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content_file_nostat.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:03:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/06 09:11:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_content_file_nostat(
			char *file_path,
			size_t *size_file,
			char **errno_str)
{
	char	*res;
	int		fd;

	res = NULL;
	if ((fd = open(file_path, O_RDONLY)) < 0)
		*errno_str = strerror(errno);
	else
	{
		res = ft_get_content_file_fd_nostat(fd, size_file, errno_str);
		if (res == NULL)
			return (NULL);
		if (close(fd) < 0)
			*errno_str = strerror(errno);
	}
	return (res);
}
