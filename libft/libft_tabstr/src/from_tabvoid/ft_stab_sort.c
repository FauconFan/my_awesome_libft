/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:38:15 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:01:13 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_tabvoid.h"

void		ft_stab_sort(char **tab, int (*f)(char *, char *))
{
	ft_vtab_sort((void **)tab, (int (*)(void *, void *))(f));
}
