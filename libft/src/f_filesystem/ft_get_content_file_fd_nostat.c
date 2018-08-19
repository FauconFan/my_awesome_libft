/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_content_file_fd_nostat.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:25:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 16:01:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_content_file_fd_nostat(int fd, char **errno_str)
{
	char			*content_file;
	char			buffer[26];
	t_sb			*lst;

	*errno_str = NULL;
	if (read(fd, buffer, 0) < 0)
	{
		*errno_str = strerror(errno);
		return (NULL);
	}
	lst = ft_sb_new();
	ft_bzero(buffer, 26);
	while (read(fd, buffer, 25))
	{
		ft_sb_append(lst, buffer);
		ft_bzero(buffer, 26);
	}
	content_file = ft_sb_tostring(lst);
	ft_sb_free(&lst);
	return (content_file);
}
