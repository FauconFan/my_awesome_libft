/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:06:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/27 08:27:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
#define FT_PRINTF_UTILS_H

# include "libft.h"

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

typedef struct				s_string_buffer
{
	char					*str;
	int						byte_stored;
	struct s_string_buffer	*next;
}							t_string_buffer;

typedef struct	s_treat_data
{
	short		hashtag_flag;
	short		zero_flag;
	short		minus_flag;
	short		plus_flag;
	short		space_flag;
	int			gabarit;
	int			precision;
	int			length_modifier_id;
	int			converter_id;
}				t_treat_data;

/*
**  ci_numbers_utils.c
*/
char	*get_rep_with_prec(va_list va, t_treat_data *res);
char	*get_prefix(char **str, t_treat_data *data);

/*
**  ci_numbers_utils_2.c
*/
char	*handle_negative_decimal_numbers(t_treat_data *data);
char	*handle_hashtag_flag(char **str, t_treat_data *data);

/*
**  ci_numbers.c
*/
void	process_numbers(va_list va, t_treat_data *data,
						t_string_buffer *sb);

/*
**	ci_sep.c
*/
void	process_sep(t_treat_data *data, t_string_buffer *sb);

/*
**	ci_string_ascii.c
*/
void	process_normal_string(va_list va, t_treat_data *data,
				t_string_buffer *sb);
void	process_normal_char(va_list va, t_treat_data *res,
				t_string_buffer *sb);

/*
**	ci_string_unicode.c
*/

int		process_special_char(va_list va, t_treat_data *data,
					t_string_buffer *sb);
int		process_special_string(va_list va, t_treat_data *data,
					t_string_buffer *sb);

int		get_byte_size(wchar_t *wstr, t_treat_data *data);
char	*fill_full_string(int max, wchar_t *wstr);

/*
**	ci_unused_flags.c
*/
void	process_unused_flag(t_treat_data *data, t_string_buffer *sb);

/*
**	set_values_treat_data.c
*/
char	*set_flags_treat_data(char *str, t_treat_data *data);
char	*set_gabarit_treat_data(char *str, t_treat_data *data, va_list va);
char	*set_precision_treat_data(char *str, t_treat_data *data, va_list va);
char	*set_length_modifer(char *str, t_treat_data *data);
char	*set_converter_treat_data(char *str, t_treat_data *data);

/*
**	set_values_treat_data2.c
*/
int		set_converter_treat_data2(char cpy);
void	update_uppercase_for_l_lm(char letter, t_treat_data *data);

/*
**	string_buffer_utils.c
*/
void	free_string_buffer(t_string_buffer *res);
void	free_last(t_string_buffer *res);

/*
**	string_buffer.c
*/
t_string_buffer				*new_string_buffer_special(
		char *str,
		int byte_stored);

t_string_buffer				*new_string_buffer_normal(
		char *str);

void						sb_append_normal(
		t_string_buffer *head,
		char *str);

void						sb_append_special(
		t_string_buffer *head,
		char *str,
		int byte_stored);

int							build_str(
		t_string_buffer *head,
		char **res);

/*
**	treat_data_utils.c
*/
int		process(char *str, va_list va, t_string_buffer *sb);

#endif
