/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:03:14 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/05 14:54:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool					f_search(void *elem_ptr, void *id_ptr)
{
	t_cmd_builder_parser_n	*elem;
	char					*id;

	elem = (t_cmd_builder_parser_n *)elem_ptr;
	id = (char *)id_ptr;
	return (ft_strcmp(id, elem->cmd) == 0);
}

static t_cmd_builder_parser_n	*check_argv(
									char *argv,
									t_opt_error *opt,
									t_slist *li_cand)
{
	t_cmd_builder_parser_n	*next_cand;

	if ((next_cand =
		ft_slist_findparam(li_cand, NULL, argv, f_search)) == NULL)
	{
		*opt = COMMAND_NOT_FOUND;
		return (NULL);
	}
	if (ft_strequ(next_cand->cmd, HELP_CMD))
	{
		*opt = HELP_CALLED;
		return (NULL);
	}
	return (next_cand);
}

int								ft_cmd_parse(
									t_cmd_builder_parser *builder,
									void ***list_tmp_way,
									t_cli_builder_parser **builder_cli,
									t_opt_error *opt)
{
	t_slist					*li_cand;
	t_cmd_builder_parser_n	*next_cand;
	int						rank_actu;

	*builder_cli = NULL;
	li_cand = builder->cmd_nodes;
	rank_actu = 1;
	next_cand = NULL;
	while (li_cand != NULL)
	{
		if (rank_actu >= builder->argc)
		{
			*opt = COMMAND_NOT_FOUND;
			return (rank_actu);
		}
		if ((next_cand =
				check_argv(builder->argv[rank_actu], opt, li_cand)) == NULL)
			return (rank_actu);
		rank_actu++;
		ft_vtab_append(list_tmp_way, next_cand, sizeof(t_cmd_builder_parser_n));
		li_cand = next_cand->sub_cmds;
	}
	*builder_cli = next_cand->cli_parser;
	return (rank_actu);
}
