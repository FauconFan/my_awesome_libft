/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/13 13:33:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	char	*s;

	s = ft_md5("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	ft_printf("%s\n", s);
	ft_strdel(&s);
	ft_putendl("a2004b1b994a6ac24bc9fa00b91e68bc");
	ft_putendl("================================");
	char	*p;

	p = ft_md4("Coucou, je m'appelle Emric.");
	ft_printf("%s\n", p);
	ft_strdel(&p);
	ft_putendl("d62b8bd8304b69219fc4ad4897337fe2");
	return 0;
}
