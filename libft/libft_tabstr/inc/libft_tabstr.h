/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tabstr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:56:00 by pepe              #+#    #+#             */
/*   Updated: 2019/08/17 11:07:06 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TABSTR_H
# define LIBFT_TABSTR_H

# include <stddef.h>
# include <stdlib.h>

/*
**	From tabvoid
*/

char			**ft_stab_new(size_t len, char *def);
void			ft_stab_free(char ***tab_ptr);
size_t			ft_stab_len(char **tab);
void			ft_stab_insert(char ***tab_ptr, size_t index, char *s);
void			ft_stab_push(char ***tab_ptr, char *s);
void			ft_stab_append(char ***tab_ptr, char *s);
void			ft_stab_delete(char ***tab_ptr, size_t i);
void			ft_stab_pop(char ***tab_ptr);
void			ft_stab_iter(char **tab, void (*f)(char *));
void			ft_stab_sort(char **tab, int (*f)(char *, char *));

/*
**	others
*/

char			*ft_stab_join(char **tab, char *joiner);
char			**ft_stab_strsplit(char const *s, char c);
unsigned int	ft_stab_strparse(char ***res, char *str, char c);
unsigned int	ft_stab_strparse_n_free(char ***res, char *str, char c);

#endif
