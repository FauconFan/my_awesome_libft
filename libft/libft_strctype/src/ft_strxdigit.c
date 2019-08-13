/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:06:34 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 18:15:38 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strctype.h"
#include "libft_ctype.h"
#include "libft_strlambda.h"

t_bool		ft_strxdigit(const char *s)
{
	return (ft_strall(s, &ft_isxdigit));
}
