/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_put.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:22:26 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 11:45:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PUT_H
# define F_PUT_H

# include "libft.h"

void			ft_putchar(char c);

void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int nb);
void			ft_putnbrl(int c);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int nb, int fd);

#endif
