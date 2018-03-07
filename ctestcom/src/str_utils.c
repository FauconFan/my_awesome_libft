/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:58:35 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/20 12:00:15 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctestcom.h"

short	iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*tct_strnew(int size)
{
	char	*str;
	int		index;

	if ((str = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		exit(1);
	index = 0;
	while (index <= size)
	{
		str[index] = 0;
		index++;
	}
	return (str);
}

char	*tct_strjoin_n_free_with_joiner(char *s1, char *s2, char *joiner)
{
	char	*str;
	int		len[3];

	len[0] = strlen(s1);
	len[1] = strlen(joiner);
	len[2] = strlen(s2);
	str = tct_strnew(len[0] + len[1] + len[2]);
	strcat(str, s1);
	strcat(str + len[0], joiner);
	strcat(str + len[0] + len[1], s2);
	free(s1);
	free(s2);
	return (str);
}

void	tct_strtrim(char **str)
{
	char	*res;
	char	*tmp;
	int		index;

	if (str == 0)
		return ;
	tmp = *str;
	while (*tmp)
	{
		if (iswhitespace(*tmp))
			tmp++;
		else
			break ;
	}
	if (*tmp == 0)
	{
		free(*str);
		*str = tct_strnew(0);
		return ;
	}
	index = strlen(tmp);
	while (--index >= 0)
	{
		if (iswhitespace(tmp[index]))
			tmp[index] = 0;
		else
			break ;
	}
	res = strdup(tmp);
	free(*str);
	*str = res;
}

char	*tct_strbuildline(char *file)
{
	char	*str;
	int		index;

	if (*file == '*' && *(file + 1) == '*')
		file += 2;
	index = 0;
	while (file[index] != 0 && file[index] != '\n')
		index++;
	str = tct_strnew(index);
	strncat(str, file, index);
	tct_strtrim(&str);
	return (str);
}
