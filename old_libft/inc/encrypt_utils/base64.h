/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:26:32 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/22 16:50:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# define ALPHA_MAJ	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define ALPHA_MIN	"abcdefghijklmnopqrstuvwxyz"
# define NUM		"0123456789"

# define B64_COMP	"="

# define B64_BASIC	ALPHA_MAJ ALPHA_MIN NUM "+/" B64_COMP
# define B64_URL	ALPHA_MAJ ALPHA_MIN NUM "-_" B64_COMP

char				*ft_base64_process(
							uint8_t *str,
							size_t len,
							char base[65]);
uint8_t				*ft_unbase64_process(
							char *str,
							size_t *len,
							char base[65]);

/*
**	ft unbase process utils...
*/

void				dnum2(char *str, uint8_t *res, char base[65]);
void				dnum3(char *str, uint8_t *res, char base[65]);
void				dnum4(char *str, uint8_t *res, char base[65]);

#endif
