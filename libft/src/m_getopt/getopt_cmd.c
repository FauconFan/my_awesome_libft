/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:34:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/02 15:43:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd_parser		*ft_getopt_cmd(
						t_cmd_config *config,
						int *argc,
						char ***argv,
						t_opt_error *err)
{
	t_cmd_builder_parser	*bd;

	bd = build_cmd_parser(config, argc, argv);
	return (ft_run_cmd(&bd, err));
}
