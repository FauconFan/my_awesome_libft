/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_content_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:09:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 16:21:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_content_file(char *file_path, char *content, char **errno_str)
{
	int		fd;

	if ((fd = open(file_path, O_WRONLY)) < 0)
	{
		*errno_str = strerror(errno);
	}
	else
	{
		ft_putstr_fd(content, fd);
		if (close(fd) < 0)
			*errno_str = strerror(errno);
	}
}
