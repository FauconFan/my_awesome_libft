/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:47:59 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/14 12:03:24 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

int		main(void)
{
	char	*str;

	str = NULL;
	assert(1);
	assertNull(str);
	assertNotNull(&main);
	free_n_print_result();
	return (0);
}
