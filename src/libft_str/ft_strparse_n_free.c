/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strparse_n_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:12:17 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:54:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strparse_n_free(char ***res, char *str, char c)
{
	int		nb_words;

	nb_words = ft_strparse(res, str, c);
	free(str);
	return (nb_words);
}
