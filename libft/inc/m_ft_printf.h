/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:27:04 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 08:13:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_FT_PRINTF_H
#define M_FT_PRINTF_H

#include "libft.h"
#include "inc/ft_printf_utils/ft_printf_utils.h"

int	ft_center_printf(const char *format, va_list va, char **answer, int *len);

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_sprintf(char **str, const char *format, ...);
int	ft_snprintf(char **str, size_t size, const char *format, ...);

int	ft_vprintf(const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);
int	ft_vsprintf(char **str, const char *format, va_list ap);
int	ft_vsnprintf(char **str,size_t size, const char *format, va_list ap);

#endif
