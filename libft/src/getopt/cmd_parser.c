/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:13:46 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/08 15:55:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char						*build_argv0(int len, char **argv)
{
	char	*res;
	size_t	len_res;
	size_t	len_actu;
	size_t	i;

	i = 0;
	len_res = 0;
	while (i < (size_t)len)
	{
		len_res += ft_strlen(argv[i]);
		i++;
	}
	len_res += len - 1;
	res = ft_strsetnew(len_res, ' ');
	len_res = 0;
	i = 0;
	while (i < (size_t)len)
	{
		len_actu = ft_strlen(argv[i]);
		ft_strncpy(res + len_res, argv[i], len_actu);
		len_res += ft_strlen(argv[i]) + 1;
		i++;
	}
	return res;
}

static int						ft_run_cmd2(
									t_cmd_builder_parser *builder,
									t_opt_error *opt,
									void ***list_tmp_way,
									t_cli_builder_parser **cand_builder)
{
	int						rank;
	size_t					len;
	t_llist					**list_to_print;
	char					*helper;
	t_cmd_builder_parser_n	*node;

	rank = ft_cmd_parse(builder, list_tmp_way, cand_builder, opt);
	builder->argv0 = build_argv0(rank, builder->argv);
	if (*opt == COMMAND_NOT_FOUND || *opt == HELP_CALLED)
	{
		len = ft_vtab_len(*list_tmp_way);
		if (len == 0)
		{
			list_to_print = &(builder->cmd_nodes);
			helper = builder->helper;
		}
		else
		{
			node = (t_cmd_builder_parser_n *)((*list_tmp_way)[len - 1]);
			list_to_print = &(node->sub_cmds);
			helper = node->helper;
		}
		handle_help_cmd(builder->argv0, list_to_print, opt, helper);
	}
	return rank;
}

static char						**build_list_commands(void **list_tmp_way)
{
	size_t		len;
	size_t		i;
	char		**l;

	i = 0;
	len = ft_vtab_len(list_tmp_way);
	ft_memcheck((l = (char **)malloc(sizeof(char *) * (len + 1))));
	while (i < len)
	{
		l[i] = ft_strdup(((t_cmd_builder_parser_n *)(list_tmp_way[i]))->cmd);
		i++;
	}
	l[i] = NULL;
	return l;
}

t_cmd_parser					*ft_run_cmd(
									t_cmd_builder_parser **builder,
									t_opt_error *opt)
{
	t_cmd_parser			*res;
	void					**list_tmp_way;
	t_cli_builder_parser	*cand_builder;
	int						rank;

	*opt = OK;
	ft_memcheck((res = (t_cmd_parser *)malloc(sizeof(t_cmd_parser))));
	res->parser = NULL;
	res->list_commands = NULL;
	list_tmp_way = ft_vtab_new(0, NULL, 0);
	rank = ft_run_cmd2(*builder, opt, &list_tmp_way, &cand_builder);
	if (*opt == OK)
	{
		res->list_commands = build_list_commands(list_tmp_way);
		(*builder)->argv[rank - 1] = ft_strdup((*builder)->argv0);
		res->parser = ft_run_cli_u(cand_builder,
							(*builder)->argc - rank + 1,
							(*builder)->argv + rank - 1,
							opt);
		ft_strdel((*builder)->argv + rank - 1);
	}
	ft_vtab_free(&(list_tmp_way));
	ft_free_cmd_builder_parser(builder);
	return res;
}

void							ft_free_cmd_parser(t_cmd_parser **pa)
{
	t_cmd_parser	*cm;

	cm = *pa;
	ft_stab_free(&(cm->list_commands));
	ft_free_cli_parser(&(cm->parser));
	free(cm);
	*pa = NULL;
}
