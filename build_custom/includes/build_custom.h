/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_custom.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:59:41 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/27 10:28:16 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_CUSTOM_H
# define BUILD_CUSTOM_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>

typedef struct		s_simple_list
{
	char					*str;
	struct s_simple_list	*next;
}					t_simple_list;

typedef struct 		s_file_depedencies
{
	char					*name_file;
	t_simple_list			*name_functions;
	t_simple_list			*name_depedencies;
}					t_file_depedencies;

typedef struct		s_list_depedencies
{
	t_file_depedencies			*content;
	struct s_list_depedencies	*next;
}					t_list_depedencies;

typedef struct		s_project_depedencies
{
	char					*path_folder;
	t_list_depedencies		*list_all_files;
}					t_project_depedencies;

/*
**	File depedencies utils
*/

t_file_depedencies		*init_file_depedencies(char *name_file, unsigned int size_tot);
void					free_file_depedencies(t_file_depedencies **elem);
void					describe_file_depedencies(t_file_depedencies *file_actu);

/*
**	Str Utilities
*/

char				*bc_strdup(char *str);
char				*bc_strndup(char *str, unsigned int size);
void				bc_update_str_still(char **str, int (*f)(char c));
void				bc_update_str_until(char **str, int (*f)(char c));
void				bc_update_str_stillstr(char **str, int (*f)(char *c));
void				bc_update_str_untilstr(char **str, int (*f)(char *c));
char				*bc_strjoin(char *s1, char *s2);
char				*bc_strjoin_folder(char *s1, char *s2);

/*
**	Malloc Utilities
*/

t_simple_list		*new_simple_list(char *str);
void				add_list_check_doublon(char *str, t_simple_list **head);
void				free_simple_list(t_simple_list **head);
t_file_depedencies	*new_file_depedencies(char *name_file);
char				**from_list_to_array(t_simple_list **head);
void				simple_display(t_simple_list *head);
int					size_simple_list(t_simple_list *tmp);
int					is_in_list(t_simple_list *head, char *str);
t_simple_list		*bc_lstiter(t_simple_list *head, char *(*treat)(char *str));

/*
**	Read Utilities
*/

int					open_read_file(char *name_file, unsigned int size_tot, char **str_tot);

/*
**	Make rendu Utilities
*/

void				handle_make_rendu(t_simple_list **list_file);

/*
**	Project Build Utilities
*/

t_project_depedencies				*build_depedencies(char *path_folder);
t_project_depedencies				*build_dep_libft(void);
void								free_depedencies(t_project_depedencies **tmp);
void								purge_depedency(t_project_depedencies *actu, t_project_depedencies *ref);
void								display_depedency(t_project_depedencies *dep);
t_simple_list						*list_dep_from_libft(
										t_project_depedencies *dep_libft,
										t_project_depedencies *dep_project);

#endif
