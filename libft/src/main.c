/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:02:01 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/05 12:44:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(void)
{
	// double res;
	//
	// res = 0;
	// while (res < 3 * FT_PI)
	// {
	// 	double s = ft_sin(res);
	// 	double c = ft_cos(res);
	// 	double t = ft_tan(res, NULL);
	// 	// printf("sin(%f) = %f\n", res, s);
	// 	// printf("cos(%f) = %f\n", res, c);
	// 	printf("tan(%f) = %f\n", res, t);
	// 	// printf("cos²(x) + sin²(x) = %f\n", (s * s + c * c));
	// 	res += FT_PI / 6;
	// }
	t_cli_parser	*parser;

	parser = ft_create_cli_parser();
	ft_free_cli_parser(parser);
	return 0;
}
