/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_make_rendu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 10:03:54 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/27 12:08:41 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

static void		handle_single_path(char *str, t_simple_list **directories_to_create)
{
	char		*tmp;
	int			pos;

	pos = 0;
	while (str[pos])
	{
		while (str[pos] != 0 && str[pos] != '/')
			pos++;
		if (str[pos] == 0)
			break ;
		tmp = bc_strndup(str, pos);
		if (strcmp(tmp, "..") != 0)
			add_list_check_doublon(tmp, directories_to_create);
		free(tmp);
		pos++;
	}
}

static void		handle_all_path(t_simple_list *list_file, t_simple_list **directories_to_create)
{
	while (list_file)
	{
		handle_single_path(list_file->str, directories_to_create);
		list_file = list_file->next;
	}
}

static char		*add_rendu_prefix(char *str)
{
	char	*res;

	if ((res = (char *)malloc(sizeof(char) * (strlen(str) + 6 + 1))) == 0)
		exit (1);
	strcpy(res, "../rendu");
	strncpy(res + 8, str + 2, strlen(str + 2) + 1);
	return (res);
}

static void		create_directories(t_simple_list *directories_to_create)
{
	while (directories_to_create)
	{
		if (mkdir(directories_to_create->str, 0755) == -1)
			dprintf(2, "%s\n", strerror(errno));
		directories_to_create = directories_to_create->next;
	}
}

static void		cpy_one_single_file(char *from, char *to)
{
	char			*file_content;
	struct stat		stats;
	int				fd;
	int				fd2;

	if (lstat(from, &stats) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	file_content = (char *)malloc(sizeof(char) * (stats.st_size + 1));
	file_content[stats.st_size] = 0;
	if ((fd = open(from, O_RDONLY)) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	if (read(fd, file_content, stats.st_size) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	if (close(fd) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	if ((fd2 = open(to, O_CREAT|O_WRONLY, 0644)) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	if (write(fd2, file_content, stats.st_size + 1) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	if (close(fd2) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	free(file_content);
}

static void		cpy_all_files(t_simple_list *list_file_from, t_simple_list *list_file_to)
{
	while (list_file_from)
	{
		cpy_one_single_file(list_file_from->str, list_file_to->str);
		list_file_from = list_file_from->next;
		list_file_to = list_file_to->next;
	}
}

static void		add_all_files_in_this_folder_recursively(t_simple_list **list_file, char *name_folder_actu)
{
	DIR				*dir_actu;
	struct dirent	*dirent_actu;
	struct stat		stat_actu;
	char			*path_file;

	if ((dir_actu = opendir(name_folder_actu)) == 0)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
	while ((dirent_actu = readdir(dir_actu)))
	{
		if (strcmp(dirent_actu->d_name, "..") == 0 ||
			strcmp(dirent_actu->d_name, ".") == 0)
			continue ;
		path_file = bc_strjoin_folder(name_folder_actu, dirent_actu->d_name);
		if (lstat(path_file, &stat_actu) == -1)
		{
			dprintf(2, "%s\n", strerror(errno));
			exit (1);
		}
		if (S_ISDIR(stat_actu.st_mode))
		{
			add_all_files_in_this_folder_recursively(list_file, path_file);
		}
		else if (S_ISREG(stat_actu.st_mode))
		{
			if (path_file[strlen(path_file) - 1] == 'h' && path_file[strlen(path_file) - 2] == '.')
				add_list_check_doublon(path_file, list_file);
			else
				dprintf(2, "WARNING this file %s may not be a header file code.\n", path_file);
		}
		else
		{
			dprintf(2, "WARNING this file type is no recognised %s\n", path_file);
		}
		free(path_file);
	}
	if (closedir(dir_actu) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit (1);
	}
}

static void		add_includes_to_list_file(t_simple_list **list_file)
{
	add_all_files_in_this_folder_recursively(list_file, "../includes");
	add_list_check_doublon("../libft.h", list_file);
}

void			handle_make_rendu(t_simple_list **list_file)
{
	t_simple_list	*directories_to_create;
	t_simple_list	*list_file_treated;

	directories_to_create = 0;
	add_includes_to_list_file(list_file);
	list_file_treated = bc_lstiter(*list_file, add_rendu_prefix);
	handle_all_path(list_file_treated, &directories_to_create);
	create_directories(directories_to_create);
	free_simple_list(&directories_to_create);
	cpy_all_files(*list_file, list_file_treated);
	free_simple_list(list_file);
	free_simple_list(&list_file_treated);
}
