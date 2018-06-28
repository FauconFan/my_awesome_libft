/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_project_depedencies.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 23:14:20 by pepe              #+#    #+#             */
/*   Updated: 2018/06/28 14:49:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

static t_list_depedencies			*new_elem_list_depedencies(t_file_depedencies *content)
{
	t_list_depedencies		*new;

	if ((new = (t_list_depedencies *)malloc(sizeof(t_list_depedencies))) == 0)
		exit (1);
	new->next = 0;
	new->content = content;
	return (new);
}

static void							add_front_list_depedencies(t_list_depedencies **head, t_file_depedencies *content)
{
	t_list_depedencies	*new;

	new = new_elem_list_depedencies(content);
	new->next = *head;
	*head = new;
}

static void							free_list_depedency(t_list_depedencies **tmp)
{
	free_file_depedencies(&((*tmp)->content));
	free(*tmp);
	*tmp = 0;
}

static void							handle_file(char *path_file, t_project_depedencies *res)
{
	if (strlen(path_file) >= 2
			&& path_file[strlen(path_file) - 2] == '.'
			&& path_file[strlen(path_file) - 1] == 'c')
		add_front_list_depedencies(&(res->list_all_files), init_file_depedencies(path_file));
	else
		dprintf(2, "WARNING this file %s may not be a file code.\n", path_file);
}

static void							handle_directories(char *path_folder, t_project_depedencies *res)
{
	DIR						*folder_project;
	struct dirent			*dirent_actu;
	struct stat				stat_actu;
	char					*path_file;

	if ((folder_project = opendir(path_folder)) == 0)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	while ((dirent_actu = readdir(folder_project)) != 0)
	{
		if (strcmp(".", dirent_actu->d_name) == 0 ||
			strcmp("..", dirent_actu->d_name) == 0)
			continue ;
		path_file = bc_strjoin_folder(path_folder, dirent_actu->d_name);
		if (lstat(path_file, &stat_actu) == -1)
		{
			dprintf(2, "%s\n", strerror(errno));
			exit (1);
		}
		if (S_ISDIR(stat_actu.st_mode))
		{
			handle_directories(path_file, res);
		}
		else if (S_ISREG(stat_actu.st_mode))
		{
			handle_file(path_file, res);
		}
		else
		{
			dprintf(2, "WARNING this file type is no recognised %s\n", path_file);
		}
		free(path_file);
	}
	if ((closedir(folder_project)) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
}

t_project_depedencies				*build_depedencies(char *path)
{
	t_project_depedencies	*res;
	struct stat				stat_actu;

	if ((res = (t_project_depedencies *)malloc(sizeof(t_project_depedencies))) == 0)
		exit (1);
	if (lstat(path, &stat_actu) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}

	res->list_all_files = 0;
	if (S_ISREG(stat_actu.st_mode))
	{
		handle_file(path, res);
	}
	else if (S_ISDIR(stat_actu.st_mode))
	{
		handle_directories(path, res);
	}
	else
	{
		dprintf(2, "WARNING this file type is no recognised %s\n", path);
		dprintf(2, "That normally never happened...\n");
		exit(1);
	}
	return (res);
}

t_project_depedencies				*build_dep_libft(void)
{
	t_project_depedencies	*res;

	res = build_depedencies("../libft/src");
	purge_depedency(res, res);
	return (res);
}

void								free_depedencies(t_project_depedencies **tmp)
{
	t_project_depedencies	*dep;
	t_list_depedencies		*list_actu;
	t_list_depedencies		*list_next;

	dep = *tmp;
	list_actu = dep->list_all_files;
	while (list_actu)
	{
		list_next = list_actu->next;
		free_list_depedency(&list_actu);
		list_actu = list_next;
	}
	free(*tmp);
	*tmp = 0;
}

static int							is_present_as_function_name(char *str, t_project_depedencies *ref)
{
	t_list_depedencies		*list_ref;
	t_file_depedencies		*file_ref;
	t_simple_list			*list_function_ref;

	list_ref = ref->list_all_files;
	while (list_ref)
	{
		file_ref = list_ref->content;
		list_function_ref = file_ref->name_functions;
		while (list_function_ref)
		{
			if (strcmp(list_function_ref->str, str) == 0)
				return (1);
			list_function_ref = list_function_ref->next;
		}
		list_ref = list_ref->next;
	}
	return (0);
}

void								purge_depedency(t_project_depedencies *actu, t_project_depedencies *ref)
{
	t_list_depedencies		*list_actu;
	t_file_depedencies		*file_actu;
	t_simple_list			*list_depe_actu;
	t_simple_list			*tmp;

	list_actu = actu->list_all_files;
	while (list_actu)
	{
		file_actu = list_actu->content;
		while (file_actu->name_depedencies != 0 && is_present_as_function_name(file_actu->name_depedencies->str, ref) == 0)
		{
			list_depe_actu = file_actu->name_depedencies->next;
			free(file_actu->name_depedencies->str);
			free(file_actu->name_depedencies);
			file_actu->name_depedencies = list_depe_actu;
		}
		if (file_actu->name_depedencies != 0)
		{
			list_depe_actu = file_actu->name_depedencies;
			while (list_depe_actu->next)
			{
				if (is_present_as_function_name(list_depe_actu->next->str, ref) == 0)
				{
					tmp = list_depe_actu->next->next;
					free(list_depe_actu->next->str);
					free(list_depe_actu->next);
					list_depe_actu->next = tmp;
				}
				else
					list_depe_actu = list_depe_actu->next;
			}
		}
		list_actu = list_actu->next;
	}
}

void								display_depedency(t_project_depedencies *dep)
{
	t_list_depedencies		*list_actu;
	t_file_depedencies		*file_actu;

	list_actu = dep->list_all_files;
	while (list_actu)
	{
		file_actu = list_actu->content;
		describe_file_depedencies(file_actu);
		list_actu = list_actu->next;
	}
}

static char							*get_file_name_from_dep_name(
										char *name_dep,
										t_file_depedencies **file_dep,
										t_project_depedencies *dep_libft)
{
	t_list_depedencies		*list_dep_libft;
	t_file_depedencies		*file_dep_libft;
	t_simple_list			*list_function_name_libft_project;

	list_dep_libft = dep_libft->list_all_files;
	while (list_dep_libft)
	{
		file_dep_libft = list_dep_libft->content;
		list_function_name_libft_project = file_dep_libft->name_functions;
		while (list_function_name_libft_project)
		{
			if (strcmp(list_function_name_libft_project->str, name_dep) == 0)
			{
				if (file_dep != 0)
					*file_dep = file_dep_libft;
				return (file_dep_libft->name_file);
			}
			list_function_name_libft_project = list_function_name_libft_project->next;
		}
		list_dep_libft = list_dep_libft->next;
	}
	return (0);
}

static void							add_dep_file(
										t_file_depedencies *file_dep,
										t_project_depedencies *dep_libft,
										t_simple_list **res)
{
	t_simple_list		*list_depedencies;
	t_file_depedencies	*file_dep_recu;
	int					size;

	list_depedencies = file_dep->name_depedencies;
	while (list_depedencies)
	{
		size = size_simple_list(*res);
		add_list_check_doublon(get_file_name_from_dep_name(list_depedencies->str, &file_dep_recu, dep_libft), res);
		if (size != size_simple_list(*res))
			add_dep_file(file_dep_recu, dep_libft, res);
		list_depedencies = list_depedencies->next;
	}
}

t_simple_list						*list_dep_from_libft(
										t_project_depedencies *dep_libft,
										t_project_depedencies *dep_project)
{
	t_simple_list			*res;
	t_list_depedencies		*list_dep_project;
	t_file_depedencies		*file_dep_project;
	t_simple_list			*list_dep_dep_project;

	t_file_depedencies		*file_dep;

	res = 0;
	list_dep_project = dep_project->list_all_files;
	while (list_dep_project)
	{
		file_dep_project = list_dep_project->content;
		list_dep_dep_project = file_dep_project->name_depedencies;
		while (list_dep_dep_project)
		{
			add_list_check_doublon(get_file_name_from_dep_name(list_dep_dep_project->str, &file_dep, dep_libft), &res);
			add_dep_file(file_dep, dep_libft, &res);
			list_dep_dep_project = list_dep_dep_project->next;
		}
		list_dep_project = list_dep_project->next;
	}
	return (res);
}
