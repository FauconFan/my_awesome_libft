/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_help_cli.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:10:20 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/08 16:40:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_helper_properly2(char **tab, int l, int r)
{
	int		len;
	int		rank;
	int		actu;

	len = 0;
	rank = 0;
	while (tab[rank] && (len + (int)ft_strlen(tab[rank]) < r - 1))
	{
		len += ft_strlen(tab[rank]) + (len != 0);
		rank++;
	}
	actu = 0;
	while (actu < rank)
	{
		if (actu != 0)
			ft_putchar(' ');
		ft_putstr(tab[actu]);
		actu ++;
	}
	if (tab[rank])
	{
		ft_putchar('\n');
		actu = 0;
		while (actu < l)
		{
			ft_putchar(' ');
			actu++;
		}
		print_helper_properly2(tab + rank, l, r);
	}
}

static void		print_helper_properly(char *helper, int l, int r)
{
	char	**tab;

	tab = ft_strsplit(helper, ' ');
	print_helper_properly2(tab, l, r);
	ft_stab_free(&tab);
}

static void		display_f(void *elem)
{
	t_cli_opt	*opt;
	char		*delim;
	char		*sh;
	char		*lo;

	opt = (t_cli_opt *)elem;
	delim = (opt->short_opt && opt->long_opt) ? ", " : "  ";
	if (opt->short_opt)
		ft_sprintf(&sh, "-%c", *(opt->short_opt));
	else
		sh = ft_strsetnew(2, ' ');
	if (opt->long_opt && opt->type)
		ft_sprintf(&lo, "--%s %s", opt->long_opt, opt->type);
	else if (opt->long_opt == NULL && opt->type == NULL)
		lo = ft_strnew(0);
	else if (opt->long_opt)
		ft_sprintf(&lo, "--%s", opt->long_opt);
	else
		lo = ft_strdup(opt->type);
	ft_printf("  %s%s%-34s", sh, delim, lo);
	if (opt->help)
		print_helper_properly(opt->help, 40, 50);
	ft_putchar('\n');
	ft_strdel(&sh);
	ft_strdel(&lo);
}

static int		cmp_f(void *d1, void *d2)
{
	t_cli_opt	*opt1;
	t_cli_opt	*opt2;

	opt1 = (t_cli_opt *)d1;
	opt2 = (t_cli_opt *)d2;
	if (opt1->long_opt != NULL && opt2->long_opt != NULL)
	{
		return ft_strcmp(opt1->long_opt, opt2->long_opt);
	}
	else if (opt1->long_opt != NULL)
	{
		if (*(opt1->long_opt) == *(opt2->short_opt))
			return (1);
		return (*(opt1->long_opt) - *(opt2->short_opt));
	}
	else if (opt2->long_opt != NULL)
	{
		if (*(opt1->short_opt) == *(opt2->long_opt))
			return (-1);
		return (*(opt1->short_opt) - *(opt2->long_opt));
	}
	return (*(opt1->short_opt) - *(opt2->short_opt));
}

void			handle_help_cli(
						char *argv0,
						t_cli_builder_parser *builder,
						t_opt_error *err)
{
	ft_llist_sort(&(builder->helps), cmp_f);
	ft_printf("Usage: %s [OPTIONS...] [ARGS...]\n\n", argv0);
	ft_printf("%s\n\n", builder->helper);
	if (err != NULL && is_user_fault(*err))
		ft_printf("%s\n\n", ft_cli_getstr_rc(*err));
	ft_putendl("Options:");
	ft_llist_iter(builder->helps, display_f);
}
