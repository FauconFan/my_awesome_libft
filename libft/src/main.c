/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/07 08:17:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			build_args(int *argc, char ***argv)
{
	*argc = 10;
	*argv = (char **)malloc(sizeof(char *) * *argc);
	(*argv)[0] = ft_strdup("-r");
	(*argv)[1] = ft_strdup("-hp");
	(*argv)[2] = ft_strdup("--name");
	(*argv)[3] = ft_strdup("google");
	(*argv)[4] = ft_strdup("-s");
	(*argv)[5] = ft_strdup("iyu");
	(*argv)[6] = ft_strdup("--sample");
	(*argv)[7] = ft_strdup("iyua");
	(*argv)[8] = ft_strdup("-s");
	(*argv)[9] = ft_strdup("iyub");
}

t_cli_builder_parser	*get_cli_builder()
{
	t_cli_builder_parser	*builder;
	t_cli_opt				*opt;
	t_cli_arg				*arg;

	builder = ft_create_cli_builder("Getopt helper");
	opt = ft_create_sl_opt('r', "reverse", "reverse output");
	arg = ft_create_bool_arg("do_reverse", FALSE);
	ft_cli_add(builder, &opt, &arg);
	opt = ft_create_s_opt('p', "use stdin");
	arg = ft_create_bool_arg("use stdin", FALSE);
	ft_cli_add(builder, &opt, &arg);
	opt = ft_create_sl_opt('n', "name", "change program name");
	arg = ft_create_string_arg("name", "getopt");
	ft_cli_add(builder, &opt, &arg);
	opt = ft_create_sl_opt('s', "sample", "give samples");
	arg = ft_create_array_arg("cli_samples");
	ft_cli_add(builder, &opt, &arg);
	return builder;
}

int				main(int argc, char **argv)
{
	t_cli_builder_parser	*builder;
	t_cli_parser			*parser;
	t_opt_error				err;
	char					**arr;

	build_args(&argc, &argv);
	builder = get_cli_builder();
	parser = ft_run_cli(&builder, argc, argv, &err);

	if (err == OK)
	{
		ft_printf("stdin %d\n", ft_cli_getb(parser, "use stdin"));
		ft_printf("reverse %d\n", ft_cli_getb(parser, "do_reverse"));
		ft_printf("name %s\n", ft_cli_gets(parser, "name"));
		arr = ft_cli_geta(parser, "cli_samples");
		ft_putendl("cli_samples :");
		ft_stab_iter(arr, (void (*)(char *))ft_putendl);
	}
	else if (has_printed_help(err) == FALSE)
	{
		ft_putendl(ft_cli_getstr_rc(err));
	}

	ft_free_cli_parser(parser);
	for (size_t i = 0; i < argc; i++) {
		free(argv[i]);
	}
	free(argv);
	return 0;
}
