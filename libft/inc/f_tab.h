/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tab.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 19:06:18 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 08:10:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_TAB_H
#define F_TAB_H

void		**ft_vtab_new(size_t len, void *def, size_t len_def);
char		**ft_stab_new(size_t len, char *def);

void		ft_vtab_free(void ***tab_ptr);
void		ft_stab_free(char ***tab_ptr);

size_t		ft_vtab_len(void **tab);
size_t		ft_stab_len(char **tab);

void		ft_vtab_insert(void ***tab_ptr, size_t index, void *s, size_t len_s);
void		ft_stab_insert(char ***tab_ptr, size_t index, char *s);

void		ft_vtab_push(void ***tab_ptr, void *s, size_t len_s);
void		ft_stab_push(char ***tab_ptr, char *s);

void		ft_vtab_append(void ***tab_ptr, void *s, size_t len_s);
void		ft_stab_append(char ***tab_ptr, char *s);

void		ft_vtab_delete(void ***tab_ptr, size_t i);
void		ft_stab_delete(char ***tab_ptr, size_t i);

void		ft_vtab_pop(void ***tab_ptr);
void		ft_stab_pop(char ***tab_ptr);

void		ft_vtab_iter(void **tab, void (*f)(void *));
void		ft_stab_iter(char **tab, void (*f)(char *));

void		ft_vtab_sort(void **tab, int (*f)(void *, void *));
void		ft_stab_sort(char **tab, int (*f)(char *, char *));

#endif
