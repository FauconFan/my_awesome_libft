/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structvb.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:11:00 by pepe              #+#    #+#             */
/*   Updated: 2019/08/17 12:12:33 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTVB_H
# define LIBFT_STRUCTVB_H

# include "libft_structslist.h"

typedef t_slist		t_vb;

typedef struct		s_void_buffer
{
	void	*buffer;
	size_t	len;
}					t_void_buffer;

t_void_buffer		*ft_vb_elem_new(void *buffer, size_t len);
void				ft_vb_elem_free(t_void_buffer *buffer);

t_vb				*ft_vb_new(void);
void				ft_vb_append(t_vb *vb, void *buff, size_t len);
void				*ft_vb_tobuffer(t_vb *vb);
void				ft_vb_free(t_vb **vb);

#endif
