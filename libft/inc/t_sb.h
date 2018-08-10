/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 10:54:53 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 11:16:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SB_H
#define T_SB_H

#include "libft.h"
#include "inc/t_slist.h"

typedef t_slist 	t_sb;

t_sb				*ft_sb_new();
void				ft_sb_append(t_sb *sb, char *str);
char				*ft_sb_tostring(t_sb *sb);
void				ft_sb_free(t_sb **sb);

#endif
