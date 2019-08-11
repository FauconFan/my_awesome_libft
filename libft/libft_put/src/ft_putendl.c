/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:18:44 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 10:00:15 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"

inline void	ft_putendl_fd(char const *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', 1);
}

inline void	ft_putendl(char const *str)
{
	ft_putendl_fd(str, 1);
}
