/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_numbers_utils2.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 07:50:26 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 08:19:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CI_NUMBERS_UTILS2_H
# define CI_NUMBERS_UTILS2_H

# include "libft.h"
# include "includes/struct_treat_data.h"
# include "includes/ci_numbers_utils.h"
# include "includes/treat_data_utils.h"

char	*handle_negative_decimal_numbers(t_treat_data *data);
char	*handle_hashtag_flag(char **str, t_treat_data *data);

#endif
