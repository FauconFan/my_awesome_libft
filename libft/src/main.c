/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/10/28 11:15:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define S1 ""
#define S2 "cou"
#define S3 "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"
#define S4 "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"
#define S5 S3 S3
#define S6 S5 S4

void	test(char *s, char *(*f)(uint8_t *, size_t))
{
	char	*str;

	ft_printf("============= %s =============\n", s);
	str = f(S1, ft_strlen(S1));
	ft_printf("%s => %s\n", "S1", str);
	ft_strdel(&str);
	str = f(S2, ft_strlen(S2));
	ft_printf("%s => %s\n", "S2", str);
	ft_strdel(&str);
	str = f(S3, ft_strlen(S3));
	ft_printf("%s => %s\n", "S3", str);
	ft_strdel(&str);
	str = f(S4, ft_strlen(S4));
	ft_printf("%s => %s\n", "S4", str);
	ft_strdel(&str);
	str = f(S5, ft_strlen(S5));
	ft_printf("%s => %s\n", "S5", str);
	ft_strdel(&str);
	str = f(S6, ft_strlen(S6));
	ft_printf("%s => %s\n", "S6", str);
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

void	test_des_func()
{
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
}

void	test_hmac_func() {
	char	*msg1 = "Sample #1";
	uint8_t	key1[64];
	char	*msg2 = "Sample #2";
	uint8_t	key2[20];
	char	*msg3 = "Sample #3";
	uint8_t	key3[100];
	char	*msg4 = "Sample #4";
	uint8_t key4[49];

	for (size_t i = 0; i < 64; i++) {
		key1[i] = i;
	}
	for (size_t i = 0; i < 20; i++) {
		key2[i] = 0x30 + i;
	}
	for (size_t i = 0; i < 100; i++) {
		key3[i] = 0x50 + i;
	}
	for (size_t i = 0; i < 49; i++) {
		key4[i] = 0x70 + i;
	}
	t_hmac		*hmac;

	hmac = ft_hmac_init(key1, 64, ft_sha1, 64);
	char *str1 = ft_hmac_process(hmac, msg1, 9);
	ft_printf("%s\n", str1);
	ft_strdel(&str1);
	ft_hmac_free(&hmac);

	hmac = ft_hmac_init(key2, 20, ft_sha1, 64);
	char *str2 = ft_hmac_process(hmac, msg2, 9);
	ft_printf("%s\n", str2);
	ft_strdel(&str2);
	ft_hmac_free(&hmac);

	hmac = ft_hmac_init(key3, 100, ft_sha1, 64);
	char *str3 = ft_hmac_process(hmac, msg3, 9);
	ft_printf("%s\n", str3);
	ft_strdel(&str3);
	ft_hmac_free(&hmac);

	hmac = ft_hmac_init(key4, 49, ft_sha1, 64);
	char *str4 = ft_hmac_process(hmac, msg4, 9);
	ft_printf("%s\n", str4);
	ft_strdel(&str4);
	ft_hmac_free(&hmac);
}

void	test_oui(char *str, uint8_t *(*f)(uint8_t *, size_t, size_t *, t_bool))
{
	uint8_t		*res;
	size_t		len;
	size_t		len_str;

	len_str = ft_strlen(str);
	res = f((uint8_t *)str, len_str, &len, TRUE);
	ft_printf("str %d\n", len_str);
	for (size_t i = 0; i < len_str; i++) {
		ft_printf("%2x ", str[i]);
	}
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("res %u\n", len);
	for (size_t i = 0; i < len; i++) {
		ft_printf("%2x ", res[i]);
	}
	ft_printf("\n");
	ft_printf("\n");
}

#define STR0 "Vivamus a enim mollis, imperdiet orci nec, porttitor velit"
#define STR1 "Vivamus a enim mollis, imperdiet orci nec, porttitor velit "
#define STR2 "Vivamus a enim mollis, imperdiet orci nec, porttitor velit   "
#define STR3 "Vivamus a enim mollis, imperdiet orci nec"

int		main()
{
	// test_hash_funcs();
	// test_des_func();
	// test_hmac_func();

	test_oui(STR0, ft_merkle_damgard_512_pad64_s32);
	test_oui(STR0, ft_merkle_damgard_512_pad64_s64);
	test_oui(STR1, ft_merkle_damgard_512_pad64_s32);
	test_oui(STR1, ft_merkle_damgard_512_pad64_s64);
	test_oui(STR2, ft_merkle_damgard_512_pad64_s32);
	test_oui(STR2, ft_merkle_damgard_512_pad64_s64);
	test_oui(STR3, ft_merkle_damgard_512_pad64_s32);
	test_oui(STR3, ft_merkle_damgard_512_pad64_s64);

	return 0;
}
