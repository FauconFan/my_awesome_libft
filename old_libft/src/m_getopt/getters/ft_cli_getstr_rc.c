/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cli_getstr_rc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:51:03 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 17:50:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_cli_getstr_rc(t_opt_error err)
{
	if (err == OK)
		return ("OK");
	else if (err == NOT_USED_WELL)
		return (D_ERR "Dont't call ft_getopt with null values.");
	else if (err == DASH_EMPTY)
		return (U_ERR "Cannot use '-' as a flag.");
	else if (err == UNKNOWN_OPTION)
		return (U_ERR "Unknown option.");
	else if (err == INTERNAL_ERROR)
		return (I_ERR "please contact joseph0priou@gmail.com.");
	else if (err == NO_NEXT_ARGUMENT_ALLOWED)
		return (U_ERR "Cannot get next argument, another option was given.");
	else if (err == NO_NEXT_ARGUMENT_GIVEN)
		return (U_ERR "Cannot get next argument, argument not given.");
	else if (err == COMMAND_NOT_FOUND)
		return (U_ERR "Command not found");
	return (NULL);
}
