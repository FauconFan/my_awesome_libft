/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:27:06 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/08 08:28:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_UTILS_H
# define F_UTILS_H

# include "libft.h"

void		ft_for(int min, int max, void (*f)(void));
void		ft_forparam(int min, int max, void (*f)(void *), void *p);

void		ft_fori(int min, int max, void (*f)(int));
void		ft_foriparam(int min, int max, void (*f)(void *, int i), void *p);

#endif
