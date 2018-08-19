/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/19 14:24:26 by jpriou           ###   ########.fr       */
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
	// test_hash_funcs();
	uint64_t key = 0x6162636461626364;
	uint64_t iv = 0x0011223344556677;
	char *msg = "oui je m'appelle Jean";
	char *msg2;
	t_des 	*des = ft_des_new(key, iv, ENCRYPT, OFB);
	uint8_t *res;
	size_t	in;
	size_t	out;

	in = ft_strlen(msg);
	res = ft_des_process(des, msg, in, &out);
	// write(1, res, out);
	ft_des_change_action(des, DECRYPT);
	msg2 = ft_des_process(des, res, out, &in);
	write(1, msg2, in);
	ft_des_free(&des);
	return 0;
}
