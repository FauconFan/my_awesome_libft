/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:24:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/02 20:37:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
#define LIBFT_MATH_H

#include "libft.h"

#define MATH_OK					0
#define MATH_NRT_EVEN_NEG		1

#define PREC_DOUBLE				1e-8

double 	ft_min(double a, double b);
double 	ft_max(double a, double b);

double 	ft_abs(double c);
double 	ft_log10(double n);
double 	ft_logb(double n, int lengthbase);

double	ft_pow(double x, size_t n);

double	ft_nrt(double, size_t n, short *rc);
double	ft_sqrt(double, short *rc);
double	ft_curt(double);

#endif
