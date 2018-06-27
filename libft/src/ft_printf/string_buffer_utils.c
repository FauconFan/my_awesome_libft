/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:22 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/26 14:24:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	free_string_buffer, assez explicit.
*/

void		free_string_buffer(
		t_string_buffer *res)
{
	if (res)
	{
		if (res->next)
			free_string_buffer(res->next);
		free(res->str);
		free(res);
	}
}

void		free_last(t_string_buffer *res)
{
	if (res == 0)
		return ;
	while (res->next->next)
		res = res->next;
	free_string_buffer(res->next);
	res->next = 0;
}
