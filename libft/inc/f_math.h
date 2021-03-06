/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_math.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:24:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 11:57:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_MATH_H
# define F_MATH_H

# include "libft.h"

# define FT_PI				3.14159265358979323846832

# define MATH_OK			0
# define MATH_NRT_EVEN_NEG	1
# define MATH_NOT_DEFINED	2

# define PREC_DOUBLE		1e-8

double						ft_min(double a, double b);
double						ft_max(double a, double b);

double						ft_abs(double c);
int							ft_log10(double n);
int							ft_logb(double n, int lengthbase);
int							ft_logi10(int n);
int							ft_logib(int n, int lengthbase);
int							ft_logll10(long long n);
int							ft_logllb(long long n, int lengthbase);
int							ft_logull10(unsigned long long n);
int							ft_logullb(unsigned long long n, int lengthbase);

double						ft_nrt(double d, size_t n, short *rc);
double						ft_sqrt(double d, short *rc);
double						ft_curt(double d);

double						ft_pow(double x, size_t n);
unsigned long long			ft_fact(unsigned long n);

double						ft_remquo(double x, double y);

double						ft_sin(double x);
double						ft_cos(double x);
double						ft_tan(double x, short *rc);

double						ft_arcsin(double x, short *rc);
double						ft_arccos(double x, short *rc);
double						ft_arctan(double x);

#endif
