/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_user_fault.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 20:23:34 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 15:38:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		is_user_fault(t_opt_error err)
{
	return (err == DASH_EMPTY
		|| err == UNKNOWN_OPTION
		|| err == NO_NEXT_ARGUMENT_ALLOWED
		|| err == NO_NEXT_ARGUMENT_GIVEN
		|| err == COMMAND_NOT_FOUND);
}

t_bool		has_printed_help(t_opt_error err)
{
	return (is_user_fault(err) || err == HELP_CALLED);
}
