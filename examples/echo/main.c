/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:00:22 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/01 17:12:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int argc, char ** argv) {
    for (int i = 1; i < argc; i++) {
        ft_putstr(argv[i]);
        if (i != argc - 1) {
            ft_putchar(' ');
        }
    }
    ft_putchar('\n');
    return 0;
}
