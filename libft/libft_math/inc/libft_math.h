/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 23:51:39 by pepe              #+#    #+#             */
/*   Updated: 2019/08/15 23:56:32 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# include <stddef.h>
# include "common.h"

# define FT_PI				3.14159265358979323846832
# define PREC_DOUBLE		1e-8

typedef enum				e_math_res
{
	MATH_OK,
	MATH_NRT_EVEN_NEG,
	MATH_NOT_DEFINED
}							t_math_res;

double						ft_min(double a, double b);
double						ft_max(double a, double b);

int							ft_abs(int c);
long int					ft_labs(long int c);
long long int				ft_llabs(long long int c);
float						ft_fabs(float c);
double						ft_dabs(double c);

int							ft_log10(double n);
int							ft_logb(double n, size_t lengthbase);
unsigned int				ft_logui10(unsigned int n);
unsigned int				ft_loguib(unsigned int n, size_t lengthbase);
unsigned int				ft_logul10(unsigned long int n);
unsigned int				ft_logulb(unsigned long int n, size_t lengthbase);
unsigned int				ft_logull10(unsigned long long int n);
unsigned int				ft_logullb(unsigned long long int n, size_t lengthbase);

double						ft_nrt(double d, size_t n, t_math_res *rc);
double						ft_sqrt(double d, t_math_res *rc);
double						ft_curt(double d);

double						ft_pow(double x, size_t n);
unsigned long long			ft_fact(unsigned long n);

double						ft_remquo(double x, double y);

double						ft_sin(double x);
double						ft_cos(double x);
double						ft_tan(double x, t_math_res *rc);

double						ft_arcsin(double x, t_math_res *rc);
double						ft_arccos(double x, t_math_res *rc);
double						ft_arctan(double x);

#endif
