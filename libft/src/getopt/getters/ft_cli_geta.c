/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cli_geta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:47:16 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 14:07:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *res_arr_void, void *target_void, void *res_void)
{
	t_res_array		*res_arr;
	char			***arr_ptr;
	char			*target;

	res_arr = (t_res_array *)res_arr_void;
	arr_ptr = (char ***)res_void;
	target = (char *)target_void;
	if (ft_strcmp(res_arr->target, target) == 0)
	{
		*arr_ptr = res_arr->value;
	}
}

char			**ft_cli_geta(t_cli_parser *parser, char *target)
{
	char	**res;

	res = NULL;
	ft_llist_iterparam2(parser->list_array, target, (void *)&res, f);
	return res;
}
