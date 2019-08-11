/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 09:49:11 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 10:51:53 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"

int			ft_atoi(char const *nptr)
{
	return (ft_atoi_base(nptr, BASE_DECA));
}
