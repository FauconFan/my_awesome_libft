/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_file_depedencies.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:16:43 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/17 17:24:06 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

t_file_depedencies	*new_file_depedencies(char *name_file)
{
	t_file_depedencies	*new;

	if ((new = (t_file_depedencies *)malloc(sizeof(t_file_depedencies))) == 0)
		exit (1);
	new->name_file = name_file;
	new->name_functions = 0;
	new->name_depedencies = 0;
	return (new);
}

void				free_file_depedencies(t_file_depedencies **elem)
{
	t_file_depedencies	*tmp;
	t_simple_list		*list;
	t_simple_list		*tmp_list;

	tmp = *elem;
	list = tmp->name_functions;
	while (list)
	{
		tmp_list = list->next;
		free(list->str);
		free(list);
		list = tmp_list;
	}
	list = tmp->name_depedencies;
	while (list)
	{
		tmp_list = list->next;
		free(list->str);
		free(list);
		list = tmp_list;
	}
	free(tmp->name_file);
	free(tmp);
	*elem = 0;
}

void				describe_file_depedencies(t_file_depedencies *file_actu)
{
	t_simple_list		*list;

	printf(" name_file : %s\n", file_actu->name_file);
	printf("   list functions\n");
	list = file_actu->name_functions;
	while (list)
	{
		printf("\t => %s\n", list->str);
		list = list->next;
	}
	printf("   list depedencies\n");
	list = file_actu->name_depedencies;
	while (list)
	{
		printf("\t => %s\n", list->str);
		list = list->next;
	}
}
