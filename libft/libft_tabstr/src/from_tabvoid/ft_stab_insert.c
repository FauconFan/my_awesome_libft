/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:12:25 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:00:44 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_tabvoid.h"
#include "libft_strstd.h"

void		ft_stab_insert(char ***tab_ptr, size_t index, char *s)
{
	ft_vtab_insert((void ***)tab_ptr, index, (void *)s, ft_strlen(s));
}
