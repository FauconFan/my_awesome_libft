/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:13:46 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 17:12:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd_parser					*ft_run_cmd(
									t_cmd_builder_parser *builder,
									t_opt_error *opt)
{
	t_cmd_parser			*res;
	void					**list_tmp_way;
	int						rank;
	t_cli_builder_parser	*cand_builder;
	size_t					len;

	*opt = OK;
	ft_memcheck((res = (t_cmd_parser *)malloc(sizeof(t_cmd_parser))));
	res->parser = NULL;
	res->list_commands = NULL;
	list_tmp_way = ft_vtab_new(0, NULL, 0);
	rank = ft_cmd_parse(builder, &list_tmp_way, &cand_builder, opt);
	if (*opt == COMMAND_NOT_FOUND)
	{
		len = ft_vtab_len(list_tmp_way);
		handle_help_cmd((len == 0)
			? &(builder->cmd_nodes)
			: (t_llist **)(list_tmp_way + len - 1), opt);
	}
	// ft_stab_iter(res->list_commands, (void (*)(char *))ft_putendl);
	ft_printf("%p\n", cand_builder);
	ft_putendl(ft_cli_getstr_rc(*opt));
	ft_printf("rank %d\n", rank);
	ft_vtab_free(&(list_tmp_way));
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
