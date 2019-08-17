/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:06:19 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:00:57 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_tabvoid.h"
#include "libft_strstd.h"

void		ft_stab_push(char ***tab_ptr, char *s)
{
	ft_vtab_push((void ***)tab_ptr, (void *)s, ft_strlen(s));
}
