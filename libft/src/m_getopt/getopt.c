/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:11:25 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 13:45:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd_parser	*ft_getopt(
						char *config,
						int *argc,
						char ***argv,
						t_opt_error *err)
{
	t_cmd_parser	*res;

	res = NULL;
	ft_putendl(config);
	(void)argc;
	(void)argv;
	(void)err;
	return res;
}
