/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 22:27:38 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 22:30:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
** Trick to avoid type cast warning on gcc8 and +
** https://github.com/libsigcplusplus/libsigcplusplus/issues/1
*/

char	*ft_str_tolower(char *str)
{
	union {
		char	(*char_ptr)(char);
		int		(*int_ptr)(int);
	} u;

	u.int_ptr = ft_tolower;
	return (ft_strmap(str, u.char_ptr));
}
