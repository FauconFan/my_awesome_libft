/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tab.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:06:18 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 20:23:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TAB_H
#define LIBFT_TAB_H

char		**ft_stab_new(size_t len, char *def);
void		ft_stab_free(char ***tab_ptr);
size_t		ft_stab_len(char **tab);

void		ft_stab_insert(char ***tab_ptr, size_t index, char *s);
void		ft_stab_push(char ***tab_ptr, char *s);
void		ft_stab_append(char ***tab_ptr, char *s);

void		ft_stab_delete(char ***tab_ptr, size_t i);
void		ft_stab_pop(char ***tab_ptr);

void		ft_stab_iter(char **tab, void (*f)(char *));

#endif
