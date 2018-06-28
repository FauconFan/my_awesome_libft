/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_origin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:56:36 by fauconfa          #+#    #+#             */
/*   Updated: 2018/06/28 15:07:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctestcom.h"

#define TESTCOM_MARKER		"** Testcom :\n"
#define SEARCHING_MODE		0
#define COPY_MODE			1
#define INCLUDES_STR		"#include \"libtestcom.h\"\n#include \"libft.h\"\n"
#define HEADER_STR			INCLUDES_STR"\nint main() {\n\tinit_env_testcom();\n"
#define TAIL_STR			"\n\tfree_n_print_result();\n\treturn (0);\n}\n"

static char		*treat_arg(t_ctestcom *ctestcom, char *str)
{
	int		mode;
	char	*line_actu;

	(void)ctestcom;
	mode = SEARCHING_MODE;
	while (*str != '\0' && (*str != '*' || *(str + 1) != '/'))
	{
		if (mode == SEARCHING_MODE && strncmp(str, TESTCOM_MARKER, strlen(TESTCOM_MARKER)) == 0)
		{
			mode = COPY_MODE;
		}
		else if (mode == COPY_MODE)
		{
			line_actu = tct_strbuildline(str);
			append_generate_string(ctestcom, strdup(line_actu));
			free(line_actu);
		}
		while (*str != '\0' && *str != '\n')
		{
			if (*str == '*' && *(str + 1) == '/')
				return (str + 2);
			str++;
		}
		if (*str == '\n')
			str++;
	}
	return (str);
}

void			tct_parser(t_ctestcom *ctestcom)
{
	char	*str;

	str = ctestcom->content_path_origin;
	while (str != NULL && *str != 0)
	{
		while (*str != '\0' && (*str != '/' || *(str + 1) != '*'))
			str++;
		if (*str == '\0')
			break ;
		str = treat_arg(ctestcom, str);
	}
}

void			tct_addcontext(t_ctestcom *ctestcom)
{
	char	*cpy;
	char	*new;

	cpy = ctestcom->generate_string;
	new = tct_strnew(strlen(HEADER_STR) + strlen(TAIL_STR) + strlen(cpy));
	strcat(new, HEADER_STR);
	strcat(new, cpy);
	strcat(new, TAIL_STR);
	free(cpy);
	ctestcom->generate_string = new;
}
