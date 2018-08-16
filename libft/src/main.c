/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/16 16:38:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define S1 ""
#define S2 "cou"
#define S3 "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"
#define S4 "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"
#define S5 S3 S3
#define S6 S5 S4

void	test(char *s, char *(*f)(char *))
{
	char	*str;

	ft_printf("============= %s =============\n", s);
	str = f(S1);
	ft_putendl(str);
	ft_strdel(&str);
	str = f(S2);
	ft_putendl(str);
	ft_strdel(&str);
	str = f(S3);
	ft_putendl(str);
	ft_strdel(&str);
	str = f(S4);
	ft_putendl(str);
	ft_strdel(&str);
	str = f(S5);
	ft_putendl(str);
	ft_strdel(&str);
	str = f(S6);
	ft_putendl(str);
	ft_strdel(&str);
}

void	test_hash_funcs()
{
	test("MD4", &ft_md4);
	test("MD5", &ft_md5);
	test("SHA1", &ft_sha1);
	test("SHA256", &ft_sha256);
	test("SHA224", &ft_sha224);
	test("SHA512", &ft_sha512);
	test("SHA384", &ft_sha384);
	test("SHA512_256", &ft_sha512_256);
	test("SHA512_224", &ft_sha512_224);
}

int		main()
{
	// char	*s;
	//
	// s = ft_unbase64("SGE=");
	// ft_putendl(s);
	// ft_strdel(&s);
	ft_printf("%8b\n", 338670);
	return 0;
}
