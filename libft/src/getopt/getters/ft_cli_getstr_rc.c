/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cli_getstr_rc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:51:03 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 15:26:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_cli_getstr_rc(t_opt_error err)
{
	if (err == OK)
		return "OK";
	else if (err == NOT_USED_WELL)
		return "Developper error: Dont't call ft_getopt with null values.";
	else if (err == DASH_EMPTY)
		return "User error: Cannot use '-' as a flag.";
	else if (err == UNKNOWN_OPTION)
		return "User error: Unknown option.";
	else if (err == INTERNAL_ERROR)
		return "Internal error: please contact joseph0priou@gmail.com.";
	else if (err == NO_NEXT_ARGUMENT_ALLOWED)
		return "User error: Cannot get next argument, another option was given.";
	else if (err == NO_NEXT_ARGUMENT_GIVEN)
		return "User error: Cannot get next argument, argument not given.";
	else if (err == COMMAND_NOT_FOUND)
		return "User error: Command not found";
	return NULL;
}
