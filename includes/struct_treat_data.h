/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_treat_data.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:20:46 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/15 12:30:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TREAT_DATA_H
# define STRUCT_TREAT_DATA_H

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

#endif
