/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 09:47:15 by pepe              #+#    #+#             */
/*   Updated: 2019/08/11 09:48:19 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PUT_H
# define LIBFT_PUT_H

# include <unistd.h>

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);

void			ft_putstr(char const *str);
void			ft_putstr_fd(char const *str, int fd);

void			ft_putendl(char const *str);
void			ft_putendl_fd(char const *str, int fd);

void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);

void			ft_putnbrl(int c);
void			ft_putnbrl_fd(int c, int fd);

#endif
