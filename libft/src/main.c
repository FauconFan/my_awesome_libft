/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/05 21:26:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_parser	*build_cli_parser()
{
	t_cli_parser		*parser;
	t_cli_arg			*bo_reverse;
	t_cli_arg			*bo_stdin;
	t_cli_arg			*name;
	t_cli_arg			*ar;

	parser = ft_create_cli_parser();
	bo_reverse = ft_create_bool_arg("reverse", TRUE);
	bo_stdin = ft_create_bool_arg("stdin", FALSE);
	name = ft_create_string_arg("name", "getopt");
	ar = ft_create_array_arg("cli_samples");

	ft_add_sl_opt(parser, 'r', "reverse", bo_reverse);
	ft_add_s_opt(parser, 'p', bo_stdin);
	ft_add_sl_opt(parser, 'n', "name", name);
	ft_add_sl_opt(parser, 's', "sample", ar);
	return parser;
}

int				main(int argc, char **argv)
{
	t_res_cli_parser	*res_parser;
	t_cli_parser		*parser;
	t_opt_error			err;
	char				**arr;

	parser = build_cli_parser();
	res_parser = ft_create_res_cli_parser(parser, argc, argv, &err);

	ft_printf("stdin %d\n", ft_cli_getb(res_parser, "stdin"));
	ft_printf("reverse %d\n", ft_cli_getb(res_parser, "reverse"));
	ft_printf("name %s\n", ft_cli_gets(res_parser, "name"));
	arr = ft_cli_geta(res_parser, "cli_samples");
	ft_stab_iter(arr, (void (*)(char *))ft_putendl);

	ft_free_res_cli_parser(res_parser);
	ft_free_cli_parser(parser);
	return 0;
}
