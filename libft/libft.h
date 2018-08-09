/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:15:24 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/09 11:52:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>

/*
**	Own defines
*/

# define MAKE_FREE_PTR(f)		((void (*)(void *))f)
# define MAKE_COPY_PTR(f)		((void *(*)(void *))f)
# define MAKE_CMP_PTR(f)		((int (*)(void *, void *))f)

# define TRUE					1
# define FALSE					0

typedef short					t_bool;

/*
**	Includes
*/

# include "includes/ft_printf.h"
# include "includes/get_next_line.h"
# include "includes/getopt.h"
# include "includes/libft_char.h"
# include "includes/libft_linked_list.h"
# include "includes/libft_math.h"
# include "includes/libft_memmory.h"
# include "includes/libft_put.h"
# include "includes/libft_str.h"
# include "includes/libft_tab.h"
# include "includes/libft_wchar.h"

#endif
