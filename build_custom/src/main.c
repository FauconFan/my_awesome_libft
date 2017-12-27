/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:59:03 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/27 13:29:05 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

static void		make_path_absolute(char **av)
{
	char	*path_actu;
	char	*str;

	if (**av != '/')
	{
		if ((path_actu = (char *)malloc(sizeof(char) * (2048))) == 0)
			exit (1);
		path_actu = getcwd(path_actu, 2048);
		str = bc_strjoin_folder(path_actu, *av);
		bc_normalize_absolute_path(str);
		*av = str;
		free(path_actu);
	}
	else
		*av = bc_strdup(*av);
}

static char		*verify_argv(char *av)
{
	struct stat		stats;

	if (*av != '/')
		return ("This path is not absolute");
	if (lstat(av, &stats) == -1)
		return ("This path don't point to a folder");
	if (S_ISDIR(stats.st_mode) == 0)
		return ("This path point to a non_folder file");
	return (0);
}

static int		is_there_a_previous_rendu_folder(void)
{
	struct stat		stats;

	if (lstat("../rendu", &stats) != -1 || errno != ENOENT)
		return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	t_project_depedencies	*dep_libft;
	t_project_depedencies	*dep_project;
	t_simple_list			*list_dep_final;
	char					*error_msg;

	if (argc != 2 || strcmp(argv[1], "") == 0)
	{
		dprintf(2, "Must specify one single argument\n");
		return (1);
	}
	make_path_absolute(argv + 1);
	if ((error_msg = verify_argv(argv[1])) != 0)
	{
		dprintf(2, "%s\n", error_msg);
		free(argv[1]);
		return (1);
	}
	if (is_there_a_previous_rendu_folder())
	{
		dprintf(2, "A file may exist in the rendu direcory\n");
		free(argv[1]);
		return (1);
	}
	dep_libft = build_dep_libft();
	dep_project = build_depedencies(argv[1]);
	purge_depedency(dep_project, dep_libft);
	list_dep_final = list_dep_from_libft(dep_libft, dep_project);
	handle_make_rendu(&list_dep_final);
	free_depedencies(&dep_libft);
	free_depedencies(&dep_project);
	free(argv[1]);
	return (0);
}
