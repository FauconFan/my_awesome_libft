/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:41:47 by pepe              #+#    #+#             */
/*   Updated: 2019/08/10 15:28:24 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "libft_ctype.h"

static void	test(t_bool (*tested)(int), int (*real)(int))
{
	for (int i = 0; i < 256; ++i)
		assert((tested(i) != 0) == (real(i) != 0));
}

int			main(void) {
	test(ft_isalnum, isalnum);
	test(ft_isalpha, isalpha);
	test(ft_isdigit, isdigit);
	test(ft_isascii, isascii);
	test(ft_isblank, isblank);
	test(ft_isprint, isprint);
	test(ft_isspace, isspace);
	test(ft_islower, islower);
	test(ft_isupper, isupper);
}
