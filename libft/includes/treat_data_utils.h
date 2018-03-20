/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:59:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 08:19:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREAT_DATA_UTILS_H
# define TREAT_DATA_UTILS_H

# include "libft.h"
# include "includes/struct_treat_data.h"
# include "includes/set_values_treat_data.h"
# include "includes/ci_string_ascii.h"
# include "includes/ci_string_unicode.h"
# include "includes/ci_sep.h"
# include "includes/ci_numbers.h"
# include "includes/ci_unused_flags.h"

# define SEPERATOR		'%'

# define HASHTAG_FLAG	'#'
# define ZERO_FLAG		'0'
# define MINUS_FLAG		'-'
# define PLUS_FLAG		'+'
# define SPACE_FLAG		' '

# define SEP_PRECISION	'.'
# define STAR_CHARACTER	'*'

/*
**	Don't change the following
**	The following connecters id are not used finally :
**	S, D, O, U, C
*/

# define LM_HH			1
# define LM_H			2
# define LM_LL			3
# define LM_L			4
# define LM_J			5
# define LM_Z			6

# define CI_SEP			9
# define CI_SMIN		10
# define CI_SMAJ		11
# define CI_P			12
# define CI_DMIN		13
# define CI_DMAJ		14
# define CI_I			15
# define CI_OMIN		16
# define CI_OMAJ		17
# define CI_UMIN		18
# define CI_UMAJ		19
# define CI_XMIN		20
# define CI_XMAJ		21
# define CI_CMIN		22
# define CI_CMAJ		23
# define CI_EMIN		24
# define CI_EMAJ		25
# define CI_FMIN		26
# define CI_FMAJ		27
# define CI_GMIN		28
# define CI_GMAJ		29
# define CI_AMIN		30
# define CI_AMAJ		31
# define CI_N			32
# define CI_Z			33
# define CI_R			34

int				process(char *str, va_list va, t_string_buffer *sb);

#endif
