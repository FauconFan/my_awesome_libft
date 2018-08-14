/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/14 13:16:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	char	*s;

	ft_putendl("============= MD5 ==============");
	s = ft_md5("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	ft_printf("%s\n", s);
	ft_strdel(&s);
	ft_putendl("2ea829477e7b8adc3821756277b76cb5");
	ft_putendl("============= MD4 ==============");
	s = ft_md4("Coucou, je m'appelle Emric.");
	ft_printf("%s\n", s);
	ft_strdel(&s);
	ft_putendl("d62b8bd8304b69219fc4ad4897337fe2");
	ft_putendl("============= SHA1 ==============");
	s = ft_sha1("Coucou, je m'appelle Emric.");
	ft_printf("%s\n", s);
	ft_strdel(&s);
	ft_putendl("8e1d0e9cf209fbbc59a6b3efa176296c9cd9f9d7");
	ft_putendl("============= SHA1 ==============");
	s = ft_sha1("");
	ft_printf("%s\n", s);
	ft_strdel(&s);
	ft_putendl("da39a3ee5e6b4b0d3255bfef95601890afd80709");
	return 0;
}
