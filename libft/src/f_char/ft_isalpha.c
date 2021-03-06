/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:07:07 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 15:44:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z')) ? TRUE : FALSE);
}
