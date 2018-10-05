/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_globals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:41:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/05 13:43:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_GLOBALS_H
# define A_GLOBALS_H

# define MAKE_FREE_PTR(f)		((void (*)(void *))f)
# define MAKE_COPY_PTR(f)		((void *(*)(void *))f)
# define MAKE_CMP_PTR(f)		((int (*)(void *, void *))f)

# define TRUE					1
# define FALSE					0

# define BASE_OCTO				"01234567"
# define BASE_DECA				"0123456789"
# define BASE_HEXAMIN			"0123456789abcdef"
# define BASE_HEXAMAJ			"0123456789ABCDEF"
# define BASE_HEXA				BASE_HEXAMAJ

typedef unsigned char			t_bool;

#endif
