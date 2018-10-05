/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:26:32 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/05 13:10:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# define ALPHA_MAJ	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define ALPHA_MIN	"abcdefghijklmnopqrstuvwxyz"
# define NUM		"0123456789"

# define B64_BASIC	ALPHA_MAJ ALPHA_MIN NUM "+/"
# define B64_URL	ALPHA_MAJ ALPHA_MIN NUM "-_"

# define B64_COMP	'='

char				*ft_base64_process(
							uint8_t *str,
							size_t len,
							char base[64],
							char comp);
uint8_t				*ft_unbase64_process(
							char *str,
							size_t *len,
							char base[64],
							char comp);

/*
**	ft unbase process utils...
*/

void				dnum2(char *str, uint8_t *res, char base[64]);
void				dnum3(char *str, uint8_t *res, char base[64]);
void				dnum4(char *str, uint8_t *res, char base[64]);

#endif
