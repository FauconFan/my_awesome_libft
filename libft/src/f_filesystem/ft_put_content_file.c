/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_content_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:09:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/09/20 09:28:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_content_file(
				char *file_path,
				char *content,
				size_t len,
				char **errno_str)
{
	int		fd;

	if ((fd = open(file_path, O_WRONLY)) < 0)
	{
		*errno_str = strerror(errno);
	}
	else
	{
		write(fd, content, len);
		if (close(fd) < 0)
			*errno_str = strerror(errno);
	}
}
