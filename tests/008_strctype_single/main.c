/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:23:30 by pepe              #+#    #+#             */
/*   Updated: 2019/08/13 18:24:19 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft_strctype.h"

int	main(void)
{
	assert(ft_stralnum("coucouocu1235768"));
	assert(ft_stralnum("coucouocu1235768:") == FALSE);
	return (0);
}
