/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:23:46 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:37:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue un nouveau string_buffer ou on différencie la taille du buffer
**	et la taille de la chaine une fois imprime (Unicode UTF-8)
*/

t_string_buffer		*new_string_buffer_special(
		char *str,
		int byte_stored)
{
	t_string_buffer	*res;

	if ((res = (t_string_buffer *)malloc(sizeof(t_string_buffer))) == 0)
		return (0);
	res->next = 0;
	res->byte_stored = byte_stored;
	res->str = ft_strdup(str);
	return (res);
}

/*
**	Alloue un nouveau string_buffer classique (Ascii)
*/

t_string_buffer		*new_string_buffer_normal(
		char *str)
{
	return (new_string_buffer_special(str, ft_strlen(str)));
}

/*
**	Rajoute un nouveau maillon a la liste chaine,
**	un maillon de string classique (Ascii)
*/

void				sb_append_normal(
		t_string_buffer *head,
		char *str)
{
	if (head == 0)
		return ;
	while (head->next)
		head = head->next;
	head->next = new_string_buffer_normal(str);
}

/*
**	Rajoute un nouveau maillon a la liste chaine,
**	un maillon de string non conventionnel ou on gere la taille
**	du buffer et la taille du buffer une fois affiché
*/

void				sb_append_special(
		t_string_buffer *head,
		char *str,
		int byte_stored)
{
	if (head == 0)
		return ;
	while (head->next)
		head = head->next;
	head->next = new_string_buffer_special(str, byte_stored);
}

/*
**	Cette fonction permet de build la string representatif du string buffer
**	donne en argument, elle renvoie le nombre de caractere que l'on va afficher
**	dans le terminal.
*/

int					build_str(
		t_string_buffer *head,
		char **res)
{
	t_string_buffer		*tmp;
	int					len_tot_stored;
	int					len_actu;

	len_tot_stored = 0;
	len_actu = 0;
	tmp = head;
	while (tmp)
	{
		len_tot_stored += tmp->byte_stored;
		tmp = tmp->next;
	}
	*res = ft_strnew(len_tot_stored);
	tmp = head;
	while (tmp)
	{
		ft_strncpy(*res + len_actu, tmp->str, tmp->byte_stored);
		len_actu += tmp->byte_stored;
		tmp = tmp->next;
	}
	return (len_tot_stored);
}
