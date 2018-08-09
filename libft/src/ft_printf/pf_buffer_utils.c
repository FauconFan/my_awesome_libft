/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:41:22 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 10:57:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static void					calculate_length(void *elem, void *param)
{
	t_pf_buffer_content		*content;
	int						*size;

	content = (t_pf_buffer_content *)elem;
	size = (int *)param;
	*size = *size + content->byte_stored;
}

static void					build_str(void *elem, void *param1, void *param2)
{
	t_pf_buffer_content		*content;
	int						*actu;
	char					**res;

	content = (t_pf_buffer_content *)elem;
	actu = (int *)param1;
	res = (char **)param2;
	ft_strncpy(*res + *actu, content->str, content->byte_stored);
	*actu = *actu + content->byte_stored;
}

int							to_string_n_free(
								t_pf_buffer **head,
								char **res,
								t_bool delete_last)
{
	int		len_tot_stored;
	int		len_actu;

	len_tot_stored = 0;
	len_actu = 0;
	if (delete_last)
		ft_llist_pop(*head);
	ft_llist_rev(*head);
	ft_llist_iterparam(*head, &len_tot_stored, calculate_length);
	*res = ft_strnew(len_tot_stored);
	ft_llist_iterparam2(*head, &len_actu, res, build_str);
	ft_llist_free(head);
	return len_tot_stored;
	// t_string_buffer		*tmp;
	// int					len_tot_stored;
	// int					len_actu;
	//
	// len_tot_stored = 0;
	// len_actu = 0;
	// tmp = head;
	// while (tmp)
	// {
	// 	len_tot_stored += tmp->byte_stored;
	// 	tmp = tmp->next;
	// }
	// *res = ft_strnew(len_tot_stored);
	// tmp = head;
	// while (tmp)
	// {
	// 	ft_strncpy(*res + len_actu, tmp->str, tmp->byte_stored);
	// 	len_actu += tmp->byte_stored;
	// 	tmp = tmp->next;
	// }
	// return (len_tot_stored);
}
