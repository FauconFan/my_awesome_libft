/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structsb.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:04:33 by pepe              #+#    #+#             */
/*   Updated: 2019/08/17 12:05:17 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTSB_H
# define LIBFT_STRUCTSB_H

# include "libft_structslist.h"

typedef t_slist		t_sb;

t_sb				*ft_sb_new(void);
void				ft_sb_append(t_sb *sb, char *str);
void				ft_sb_append_char(t_sb *sb, char c, size_t len);
char				*ft_sb_tostring(t_sb *sb);
void				ft_sb_free(t_sb **sb);

#endif
