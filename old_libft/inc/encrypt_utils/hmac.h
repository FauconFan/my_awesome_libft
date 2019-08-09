/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:42:37 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 11:48:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAC_H
# define FT_HMAC_H

# define IPAD_CHAR	0x36
# define OPAD_CHAR	0x5c

typedef struct		s_hmac
{
	uint8_t		*key;
	char		*(*hash_f)(uint8_t *, size_t);
	size_t		size_block;
}					t_hmac;

#endif
