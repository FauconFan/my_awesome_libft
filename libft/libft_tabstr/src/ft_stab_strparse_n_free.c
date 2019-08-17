/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_strparse_n_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:12:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:11:09 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"

unsigned int	ft_stab_strparse_n_free(char ***res, char *str, char c)
{
	unsigned int	nb_words;

	nb_words = ft_stab_strparse(res, str, c);
	free(str);
	return (nb_words);
}
