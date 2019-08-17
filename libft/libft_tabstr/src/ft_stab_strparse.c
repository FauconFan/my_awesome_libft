/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_strparse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:44:41 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:05:47 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_strstd.h"
#include "libft_memory.h"

static unsigned int	ft_getnb_words(char *str, char c)
{
	int				index;
	unsigned int	nb_words;

	index = 0;
	nb_words = 1;
	while (str[index])
	{
		if (str[index] == c)
		{
			nb_words++;
		}
		index++;
	}
	return (nb_words);
}

unsigned int		ft_stab_strparse(char ***res, char *str, char c)
{
	unsigned int	nb_words;
	unsigned int	index;
	int				place;

	nb_words = ft_getnb_words(str, c);
	ft_memcheck((*res = (char **)malloc(sizeof(char *) * (nb_words + 1))));
	(*res)[nb_words] = 0;
	index = 0;
	while (index < nb_words)
	{
		place = ft_strcpos(str, c);
		if (place == -1)
			place = (int)ft_strlen(str);
		(*res)[index] = ft_strnew((size_t)place);
		ft_strncpy((*res)[index], str, (size_t)place);
		str = str + place + 1;
		index++;
	}
	return (nb_words);
}
