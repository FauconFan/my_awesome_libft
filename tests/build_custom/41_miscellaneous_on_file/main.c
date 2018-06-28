/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:48:15 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/29 18:51:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(void)
{
	ft_strncmp("coucou", "coucousdcjdk", 2);
	ft_strstr("coucou", "cou");
	ft_printf("vive les haricots\n");
	ft_printf("vive les haricots %d\n", 2);
	free(ft_itoa(56));
	char *str = ft_strndup("skdjskjdksjkdajdlsajdlasjd", 6);
	ft_memcheck((str));
	ft_strdel(&str);
	ft_isblank('f');
	return (0);
}
