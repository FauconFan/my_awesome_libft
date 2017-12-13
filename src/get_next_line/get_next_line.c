/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 09:38:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	How to use the new get_next_line :
**	You have to instance a struct of t_env_gnl with the function init_env_gnl
**	int the env_gnl.c file.
**	Then the prototype of the function get_next_line has changed, you have to
**	as a argument this instance of t_env_gnl.
**	Then, at the end of your program you have to call the function free_env_gnl
**	to free everything and prevent memmory leaks...
**
**	I did this to remove the static variable.
*/

static void		fill_line(char **line, char **buff_prog)
{
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	tmp = 0;
	while ((*buff_prog)[i] != '\n' && (*buff_prog)[i])
		i++;
	*line = ft_strsub(*buff_prog, 0, i);
	size = 0;
	while ((*buff_prog)[i + size] != 0)
		size++;
	tmp = ft_strsub(*buff_prog, i + 1, size);
	free(*buff_prog);
	*buff_prog = tmp;
}

static int		loop(const int fd, char **buff_prog)
{
	char	*tmp;
	char	*buff;
	int		ret;

	buff = 0;
	ret = 0;
	if (ft_strchr(*buff_prog, '\n') == 0)
		buff = ft_strnew(BUFF_SIZE_GNL + 1);
	while (ft_strchr(*buff_prog, '\n') == 0)
	{
		ft_bzero(buff, BUFF_SIZE_GNL + 1);
		if ((ret = read(fd, buff, BUFF_SIZE_GNL)) == -1)
			break ;
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		tmp = ft_strjoin(*buff_prog, buff);
		free(*buff_prog);
		*buff_prog = tmp;
		if (ft_strlen(buff) < BUFF_SIZE_GNL)
			break ;
	}
	if (buff != 0)
		free(buff);
	return ((ret == -1) ? -1 : 0);
}

int				get_next_line(const int fd, char **line, t_env_gnl *env_gnl)
{
	char		**buff_prog;

	if (line == 0 || read(fd, 0, 0) < 0)
		return (-1);
	buff_prog = find_buff_prog(env_gnl, (int)fd);
	if (loop(fd, buff_prog) == -1)
		return (-1);
	if (**buff_prog == 0)
		return (0);
	fill_line(line, buff_prog);
	return (1);
}
