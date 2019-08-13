/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:20:41 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 18:15:23 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strctype.h"
#include "libft_ctype.h"
#include "libft_strlambda.h"

t_bool		ft_strascii(const char *s)
{
	return (ft_strall(s, &ft_isascii));
}
