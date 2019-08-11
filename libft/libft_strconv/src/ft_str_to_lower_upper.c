/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lower_upper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 10:47:37 by pepe              #+#    #+#             */
/*   Updated: 2019/08/11 11:06:47 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"
#include "libft_ctype.h"

static char	*ft_str_treat(char *str, int (*func)(int))
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = func(str[i]);
		++i;
	}
	return (str);
}

char		*ft_str_toupper(char *str)
{
	return (ft_str_treat(str, ft_toupper));
}

char		*ft_str_tolower(char *str)
{	
	return (ft_str_treat(str, ft_tolower));
}