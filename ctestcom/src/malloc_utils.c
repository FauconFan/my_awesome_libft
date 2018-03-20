/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:17:41 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/20 10:18:20 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctestcom.h"

t_ctestcom		*init_ctestcom(char *path_origin, char *path_target)
{
	t_ctestcom	*res;

	if ((res = (t_ctestcom *)malloc(sizeof(t_ctestcom))) == 0)
		exit(1);
	res->path_origin = path_origin;
	res->path_target = path_target;
	if ((res->fd_target = open(path_target, O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
	{
		dprintf(2, "Couldn't open the target file...\nerror : %s\n", strerror(errno));
		exit(1);
	}
	res->content_path_origin = get_file_content(path_origin);
	res->generate_string = tct_strnew(0);
	return (res);
}

void			free_ctestcom(t_ctestcom **ctestcom)
{
	free((*ctestcom)->content_path_origin);
	free((*ctestcom)->generate_string);
	free(*ctestcom);
	*ctestcom = 0;
}

void			append_generate_string(t_ctestcom *ctestcom, char *str)
{
	char	*final_joiner;

	if (str[strlen(str) - 1] == ';')
		final_joiner = "\n";
	else
		final_joiner = ";\n";
	ctestcom->generate_string = tct_strjoin_n_free_with_joiner(
		ctestcom->generate_string, str, "\t");
	ctestcom->generate_string = tct_strjoin_n_free_with_joiner(
		ctestcom->generate_string,
		tct_strnew(0),
		final_joiner);
}
