/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:18:07 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:36:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_NUMBERS_UTILS_H
# define CI_NUMBERS_UTILS_H

# include "libft.h"
# include "struct_treat_data.h"
# include "ci_numbers_utils2.h"

# define PREFIX_XMIN	"0x"
# define PREFIX_XMAJ	"0X"
# define ZERO_SOLO		"0"
# define MINUS_SOLO		"-"
# define PLUS_SOLO		"+"
# define SPACE_SOLO		" "

# define BASE_DECA		"0123456789"
# define BASE_OCTO		"01234567"
# define BASE_HEXAMIN	"0123456789abcdef"
# define BASE_HEXAMAJ	"0123456789ABCDEF"

char						*get_rep_with_prec(va_list va, t_treat_data *res);
char						*get_prefix(char **str, t_treat_data *data);

#endif
