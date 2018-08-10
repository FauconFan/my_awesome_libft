/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/10 11:17:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	t_sb	*sb;
	char	*str;

	sb = ft_sb_new();
	ft_sb_append(sb, "Oui");
	ft_sb_append(sb, ", ");
	ft_sb_append(sb, "je");
	ft_sb_append(sb, " m'appelle");
	ft_sb_append(sb, " Jean");
	str = ft_sb_tostring(sb);
	ft_putendl(str);
	ft_strdel(&str);
	ft_sb_free(&sb);
	return 0;
}
