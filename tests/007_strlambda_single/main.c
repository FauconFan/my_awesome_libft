/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:52:37 by pepe              #+#    #+#             */
/*   Updated: 2019/08/13 18:07:17 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <ctype.h>
#include "libft_strlambda.h"

t_bool	ft_isalpha(int c)
{
	return (isalpha(c) != 0);
}

int	main(void)
{
	assert(ft_strall("", ft_isalpha));
	assert(ft_strall("a", ft_isalpha));
	assert(ft_strall("abc", ft_isalpha));
	assert(ft_strany("123456a", ft_isalpha));
}
