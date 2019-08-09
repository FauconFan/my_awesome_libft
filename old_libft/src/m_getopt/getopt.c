/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:11:25 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/02 15:44:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_parser		*ft_getopt(
						t_cli_config *config,
						int *argc,
						char ***argv,
						t_opt_error *err)
{
	t_cli_builder_parser	*bd;

	bd = build_cli_parser(config);
	return (ft_run_cli(&bd, argc, argv, err));
}
