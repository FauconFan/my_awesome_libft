/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:01:32 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:00:01 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_tabvoid.h"

void			ft_stab_free(char ***tab_ptr)
{
	ft_vtab_free((void ***)tab_ptr);
}