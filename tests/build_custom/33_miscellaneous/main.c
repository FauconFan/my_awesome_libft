/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:00:14 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/29 19:03:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(void)
{
	char		*str;

	str = ft_strnew(2048);
	ft_strcat(str, "coucou");
	ft_strcpy(str + 6, " je mappelle jean ");
	ft_strcat(str, " et jhabite paris\n");
	ft_strcat(str, "pas du tout jai menti");
	ft_strncat(str, "ahlahlahlah", 6);
	ft_putstr(str);
	ft_strclr(str);
	ft_strdel(&str);
	ft_putstr(str);
}