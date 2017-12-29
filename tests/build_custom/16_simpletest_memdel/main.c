/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:58:47 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/29 18:01:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (7));
	if (str == 0)
		return (1);
	str[0] = 'c';
	str[1] = 'o';
	str[2] = 'u';
	str[3] = 'c';
	str[4] = 'o';
	str[5] = 'u';
	str[6] = '\0';
	ft_memdel((void **)&str);
	printf("%s\n", "done successfully");
	return (0);
}
