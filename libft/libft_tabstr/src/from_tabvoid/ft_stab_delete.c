/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:13:42 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 10:59:59 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_tabvoid.h"

void			ft_stab_delete(char ***tab_ptr, size_t i)
{
	ft_vtab_delete((void ***)tab_ptr, i);
}
