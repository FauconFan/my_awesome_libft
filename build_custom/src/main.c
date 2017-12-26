/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:59:03 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/26 18:56:43 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

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

int				main(int argc, char **argv)
{
	t_project_depedencies	*dep_libft;
	t_project_depedencies	*dep_project;
	t_simple_list			*list_dep_final;
	char					*error_msg;

	if (argc != 2)
	{
		dprintf(2, "Must specify one single argument\n");
		return (1);
	}
	else if ((error_msg = verify_argv(argv[1])) != 0)
	{
		dprintf(2, "%s\n", error_msg);
		return (1);
	}
	dep_libft = build_dep_libft();
	dep_project = build_depedencies(argv[1]);
	purge_depedency(dep_project, dep_libft);
	list_dep_final = list_dep_from_libft(dep_libft, dep_project);
	simple_display(list_dep_final);
	free_simple_list(&list_dep_final);
	free_depedencies(&dep_libft);
	free_depedencies(&dep_project);
	return (0);
}
