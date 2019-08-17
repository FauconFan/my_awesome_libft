/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 20:02:05 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:00:06 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_tabvoid.h"

void		ft_stab_iter(char **tab, void (*f)(char *))
{
	ft_vtab_iter((void **)tab, (void (*)(void *))f);
}
