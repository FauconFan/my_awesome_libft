/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:33:59 by pepe              #+#    #+#             */
/*   Updated: 2019/08/13 17:38:12 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft_strconv.h"

int		main(void)
{
	char		*number = "123456789";
	char		*number12 = ft_convert_base(number, BASE_DECA, BASE_OCTO);

	if (strcmp(number12, "726746425") != 0)
		return (1);
	free(number12);
	return (0);
}
