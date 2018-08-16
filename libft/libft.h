/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:15:24 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/16 09:01:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>


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

# include "inc/f_char.h"
# include "inc/f_encrypt.h"
# include "inc/f_filesystem.h"
# include "inc/f_math.h"
# include "inc/f_memmory.h"
# include "inc/f_put.h"
# include "inc/f_str.h"
# include "inc/f_tab.h"
# include "inc/f_utils.h"
# include "inc/f_wchar.h"
# include "inc/m_ft_printf.h"
# include "inc/m_getopt.h"
# include "inc/m_regex.h"
# include "inc/t_sb.h"
# include "inc/t_slist.h"

#endif
