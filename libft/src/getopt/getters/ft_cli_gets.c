/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cli_gets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:47:16 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 21:14:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *res_str_void, void *target_void, void *res_void)
{
	t_res_string	*res_str;
	char			**str_ptr;
	char			*target;

	res_str = (t_res_string *)res_str_void;
	str_ptr = (char **)res_void;
	target = (char *)target_void;
	if (ft_strcmp(res_str->target, target) == 0)
	{
		*str_ptr = res_str->value;
	}
}

char			*ft_cli_gets(t_res_cli_parser *parser, char *target)
{
	char	*res;

	res = NULL;
	ft_llist_iterparam2(parser->list_string, target, &res, f);
	return res;
}
