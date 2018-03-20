/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_primitives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 10:00:25 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/20 16:55:34 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

# define FUNC_CON()				add_test_to_env(init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp)));
# define FUNC_PROTO(type)		type a, type b, int comp

void		assert_char(FUNC_PROTO(char)){
	FUNC_CON()
}

void		assert_short(FUNC_PROTO(short)){
	FUNC_CON()
}

void		assert_int(FUNC_PROTO(int)){
	FUNC_CON()
}

void		assert_long(FUNC_PROTO(long)){
	FUNC_CON()
}

void		assert_long_long(FUNC_PROTO(long long)){
	FUNC_CON()
}

void		assert_float(FUNC_PROTO(float)){
	FUNC_CON()
}

void		assert_double(FUNC_PROTO(double)){
	FUNC_CON()
}

void		assert_long_double(FUNC_PROTO(long double)){
	FUNC_CON()
}

void		assert_unsigned_char(FUNC_PROTO(unsigned char)){
	FUNC_CON()
}

void		assert_unsigned_short(FUNC_PROTO(unsigned short)){
	FUNC_CON()
}

void		assert_unsigned_int(FUNC_PROTO(unsigned int)){
	FUNC_CON()
}

void		assert_unsigned_long(FUNC_PROTO(unsigned long)){
	FUNC_CON()
}

void		assert_unsigned_long_long(FUNC_PROTO(unsigned long long)){
	FUNC_CON()
}

