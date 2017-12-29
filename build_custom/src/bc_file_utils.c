/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:37:54 by pepe              #+#    #+#             */
/*   Updated: 2017/12/29 18:17:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

static int				bc_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int				bc_isblank(char c)
{
	return (c == ' ' || c == '\t');
}

static int				bc_isnotspace(char c)
{
	return (bc_isspace(c) == 0);
}

static int				bc_detect_beginning_commentary1(char *str)
{
	if (*str == '/' && *(str + 1) == '/')
		return (1);
	return (0);
}

static int				bc_detect_beginning_commentary2(char *str)
{
	if (*str == '/' && *(str + 1) == '*')
		return (1);
	return (0);
}

static int				bc_detect_end_commentary2(char *str)
{
	return (*str == '*' && *(str + 1) == '/');
}

static int				bc_detect_end_of_line(char c)
{
	return (c == '\n');
}

static int				bc_detect_hashtag(char c)
{
	return (c == '#');
}

static int				bc_detect_ignorable_character(char *c)
{
	return ((*c == '(' || *c == '{' ||
		*c == '}' ||
		(*c == '/' && (*(c + 1) == '/' || (*(c + 1)) == '*')) ||
		*c == '#') == 0);
}

static int				check_forbidden_function(char *str)
{
	char	*list_forbidden[] = {"free", "malloc", "sizeof",
							"read", "opendir", "closedir", "open", "close", "readdir", "lstat",
							"if", "while", "return",
							"&&", "||", "+",
							"-", "*", "/", "%", "=", "==", "<=", ">=", 0};
	int		i;

	i = -1;
	if (*str == '(')
		return (1);
	while (list_forbidden[++i])
	{
		if (strcmp(str, list_forbidden[i]) == 0)
			return (1);
	}
	return (0);
}

static char				*verify_static_function(char *str_tot)
{
	int		index;
	char	*name_function;

	name_function = str_tot;
	while (*str_tot != '\n' && *(str_tot - 1) != '\n')
	{
		if (*str_tot == '\n')
			str_tot--;
		while (bc_isblank(*str_tot))
			str_tot--;
		index = 0;
		while (bc_isspace(*str_tot) == 0)
		{
			str_tot--;
			index++;
		}
		if (index == 6 && strncmp("static", str_tot + 1, 6) == 0)
		{	
			name_function--;
			while (bc_isspace(*name_function))
				name_function--;
			index = 0;
			while (bc_isnotspace(*name_function) && *name_function != '(' && *name_function != ')' && *name_function != '*')
			{
				name_function--;
				index++;
			}
			name_function++;
			return (bc_strndup(name_function, index));
		}
	}
	return (0);
}

static void				handle_function_ptr_as_argument(char *cpy, t_simple_list **list)
{
	char	*tmp;
	char	*tmp2;
	int		pos;

	if ((pos = bc_strcpos(cpy, ',')) == -1)
	{
		while (bc_isspace(*cpy))
			cpy++;
		if (*cpy == '&')
			cpy++;
		if ((((*cpy >= 'a' && *cpy <= 'z')) || (*cpy >= 'A' && *cpy <= 'Z')) == 0)
			return ;
		if (bc_strcpos(cpy, '(') != -1 ||
			bc_strcpos(cpy, ')') != -1 ||
			bc_strcpos(cpy, '+') != -1 ||
			bc_strcpos(cpy, '-') != -1 ||
			bc_strcpos(cpy, '&') != -1 ||
			bc_strcpos(cpy, '|') != -1 ||
			bc_strcpos(cpy, '^') != -1 ||
			bc_strcpos(cpy, '*') != -1 ||
			bc_strcpos(cpy, '/') != -1 ||
			bc_strcpos(cpy, '%') != -1 ||
			bc_strcpos(cpy, '<') != -1 ||
			bc_strcpos(cpy, '=') != -1 ||
			bc_strcpos(cpy, '[') != -1 ||
			bc_strcpos(cpy, ']') != -1 ||
			bc_strcpos(cpy, '>') != -1 ||
			bc_strcpos(cpy, ' ') != -1 ||
			strlen(cpy) <= 3 ||
			strcmp(cpy, "NULL") == 0 ||
			strcmp(cpy, "void") == 0 ||
			strcmp(cpy, "char") == 0 ||
			strcmp(cpy, "little") == 0 ||
			strcmp(cpy, "needle") == 0 ||
			strcmp(cpy, "TRUE") == 0 ||
			strcmp(cpy, "FALSE") == 0 ||
			strcmp(cpy, "data") == 0 ||
			strcmp(cpy, "null") == 0 ||
			strcmp(cpy, "length") == 0 ||
			strcmp(cpy, "base") == 0 ||
			strcmp(cpy, "lengthbase") == 0 ||
			strcmp(cpy, "index") == 0 ||
			strcmp(cpy, "size") == 0 ||
			strcmp(cpy, "format") == 0 ||
			strcmp(cpy, "baselen") == 0 ||
			strcmp(cpy, "dest") == 0 ||
			strcmp(cpy, "nb_words") == 0)
				return ;
		printf("%s\n", cpy);
		add_list_check_doublon(cpy, list);
	}
	else
	{
		tmp = bc_strndup(cpy, pos);
		tmp2 = bc_strdup(cpy + pos + 1);
		handle_function_ptr_as_argument(tmp, list);
		handle_function_ptr_as_argument(tmp2, list);
		free(tmp);
		free(tmp2);
	}
}

static void				add_name_to_list(char *str, t_simple_list **list)
{
	unsigned int		index;
	char				*string_to_add;
	char				*string_to_treat;
	char				*cpy;

	cpy = str;
	str--;
	while (bc_isspace(*str))
		str--;
	index = 0;
	while (bc_isnotspace(*str) && *str != '(' && *str != ')' && *str != '*')
	{
		str--;
		index++;
	}
	str++;
	if (check_forbidden_function(str) == 0)
	{
		string_to_add = bc_strndup(str, index);
		add_list_check_doublon(string_to_add, list);
		free(string_to_add);
	}
	index = 0;
	cpy++;
	while (cpy[index] != ')' && cpy[index] != 0)
		index++;
	string_to_treat = bc_strndup(cpy, index);
	handle_function_ptr_as_argument(string_to_treat, list);
	free(string_to_treat);
}

static void				update_until_next_function_declaration(char **str_tot)
{
	char	*tmp;
	int		depth;

	tmp = *str_tot;
	tmp++;
	depth = 1;
	while (*tmp && depth != 0)
	{
		if (*tmp == '(')
			depth++;
		else if (*tmp == ')')
			depth--;
		tmp++;
	}
	*str_tot = tmp;
}

static void				remove_static_depedencies_and_free_them(t_simple_list **list_depedencies, t_simple_list **list_static_function)
{
	int				is_static;
	t_simple_list	*pk_depedencies;
	t_simple_list	*pk_static;
	char			*str_actu;

	while (*list_depedencies)
	{
		str_actu = (*list_depedencies)->str;
		pk_static = *list_static_function;
		is_static = 0;
		while (pk_static)
		{
			if (strcmp(str_actu, pk_static->str) == 0)
			{
				is_static = 1;
				break ;
			}
			pk_static = pk_static->next;
		}
		if (is_static)
		{
			pk_static = (*list_depedencies)->next;
			free((*list_depedencies)->str);
			free(*list_depedencies);
			*list_depedencies = pk_static;
		}
		else
			break ;
	}
	pk_depedencies = *list_depedencies;
	if (pk_depedencies)
	{
		while (pk_depedencies->next)
		{
			str_actu = pk_depedencies->next->str;
			pk_static = *list_static_function;
			is_static = 0;
			while (pk_static)
			{
				if (strcmp(str_actu, pk_static->str) == 0)
				{
					is_static = 1;
					break ;
				}
				pk_static = pk_static->next;
			}
			if (is_static)
			{
				pk_static = pk_depedencies->next->next;
				free(pk_depedencies->next->str);
				free(pk_depedencies->next);
				pk_depedencies->next = pk_static;
			}
			else
			{
				pk_depedencies = pk_depedencies->next;
			}
		}
	}
	pk_static = *list_static_function;
	while(pk_static)
	{
		pk_depedencies = pk_static->next;
		free(pk_static->str);
		free(pk_static);
		pk_static = pk_depedencies;
	}
	*list_static_function = 0;
}

t_file_depedencies		*init_file_depedencies(char *name_file, unsigned int size_tot)
{
	t_file_depedencies		*res;
	t_simple_list			*list_function_name;
	t_simple_list			*list_depedencies;
	t_simple_list			*list_static_function;
	char					*name_function_static_actu;
	char					*str_tot;
	char					*str_cpy;
	int						depth;
	int						fd;

	res = new_file_depedencies(name_file);
	if ((str_tot = (char *)malloc(sizeof(char) * (size_tot + 1))) == 0)
		exit(1);
	fd = open_read_file(name_file, size_tot, &str_tot);
	str_cpy = str_tot;
	depth = 0;
	list_function_name = 0;
	list_depedencies = 0;
	list_static_function = 0;
	while (*str_tot)
	{
		if (bc_detect_beginning_commentary1(str_tot))
		{
			bc_update_str_until(&str_tot, bc_detect_end_of_line);
		}
		else if (bc_detect_beginning_commentary2(str_tot))
		{
			bc_update_str_untilstr(&str_tot, bc_detect_end_commentary2);
			str_tot += 2;
		}
		else if (bc_detect_hashtag(*str_tot))
		{
			bc_update_str_until(&str_tot, bc_detect_end_of_line);
		}
		else if (*str_tot == '(')
		{
			if (depth == 0)
			{
				name_function_static_actu = verify_static_function(str_tot);
				if (name_function_static_actu == 0)
					add_name_to_list(str_tot, &list_function_name);
				else
				{
					add_list_check_doublon(name_function_static_actu, &list_static_function);
					free(name_function_static_actu);
				}
				update_until_next_function_declaration(&str_tot);
			}
			else
			{
				add_name_to_list(str_tot, &list_depedencies);
				str_tot++;
			}
		}
		else if (*str_tot == '{')
		{
			depth++;
			str_tot++;
		}
		else if (*str_tot == '}')
		{
			depth--;
			str_tot++;
		}
		else
		{
			bc_update_str_stillstr(&str_tot, bc_detect_ignorable_character);
		}
	}
	remove_static_depedencies_and_free_them(&list_depedencies, &list_static_function);
	res->name_file = bc_strdup(name_file);
	res->name_functions = list_function_name;
	res->name_depedencies = list_depedencies;
	free(str_cpy);
	if (close(fd) == -1)
	{
		dprintf(2, "%s\n", strerror(errno));
		exit(1);
	}
	return (res);
}
