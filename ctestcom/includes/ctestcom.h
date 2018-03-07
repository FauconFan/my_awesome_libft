/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctestcom.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:17:21 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/07 13:34:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTESTCOM_H
# define CTESTCOM_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef	struct		s_ctestcom
{
	char		*path_origin;
	char		*path_target;
	int			fd_target;
	char		*content_path_origin;
	char		*generate_string;
}					t_ctestcom;

/*
**	Malloc Utils
*/

t_ctestcom		*init_ctestcom(char *path_origin, char *path_target);
void			free_ctestcom(t_ctestcom **ctestcom);
void			append_generate_string(t_ctestcom *ctestcom, char *str);

/*
**	Get file content
*/

char			*get_file_content(char *path);

/*
**	Parser utis
*/

void			tct_parser(t_ctestcom *ctestcom);
void			tct_addcontext(t_ctestcom *ctestcom);

/*
**	Str utils
*/

char			*tct_strnew(int size);
char			*tct_strjoin_n_free_with_joiner(char *s1, char *s2, char *joiner);
void			tct_strtrim(char **str);
char			*tct_strbuildline(char *file);

#endif
