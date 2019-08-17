/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tabvoid.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 00:28:52 by pepe              #+#    #+#             */
/*   Updated: 2019/08/16 00:31:54 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TABVOID_H
# define LIBFT_TABVOID_H

# include <stdlib.h>
# include <stddef.h>

void	**ft_vtab_new(size_t len, void *def, size_t len_def);
void	ft_vtab_free(void ***tab_ptr);
size_t	ft_vtab_len(void **tab);
void	ft_vtab_insert(void ***tab_ptr, size_t index, void *s, size_t len_s);
void	ft_vtab_push(void ***tab_ptr, void *s, size_t len_s);
void	ft_vtab_append(void ***tab_ptr, void *s, size_t len_s);
void	ft_vtab_delete(void ***tab_ptr, size_t i);
void	ft_vtab_pop(void ***tab_ptr);
void	ft_vtab_iter(void **tab, void (*f)(void *));
void	ft_vtab_sort(void **tab, int (*f)(void *, void *));

#endif
