/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/13 12:12:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	char	*s;

	s = ft_md5("N importe quoi ! Je t aime ! \n");
	ft_printf("%s\n", s);
	ft_strdel(&s);
	ft_putendl("39a347d0cbf89957e3a28c5007dd3032");
	ft_putendl("================================");
	char	*p;

	p = ft_md4("Coucou, je m'appelle Emric.");
	ft_printf("%s\n", p);
	ft_strdel(&p);
	ft_putendl("d62b8bd8304b69219fc4ad4897337fe2");
	return 0;
}
