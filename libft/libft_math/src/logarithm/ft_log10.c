/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:42:12 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/24 22:22:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

int			ft_log10(double n)
{
	return (ft_logb(n, 10));
}
