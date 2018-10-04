/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_arg_gettype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:24:10 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 15:28:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_cli_arg_get_type(t_cli_arg *arg)
{
	if (ft_cli_is_bool(arg))
	{
		return (NULL);
	}
	else if (ft_cli_is_string(arg))
	{
		return (ft_strdup("string"));
	}
	else if (ft_cli_is_array(arg))
	{
		return (ft_strdup("list"));
	}
	return (NULL);
}
