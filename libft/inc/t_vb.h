/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 08:26:19 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/30 08:46:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VB_H
# define T_VB_H

# include "libft.h"
# include "inc/t_slist.h"

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
