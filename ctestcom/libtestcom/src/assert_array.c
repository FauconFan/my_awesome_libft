/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:31:19 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/25 17:01:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

# define NUM_EQUALS(a, b)           ((a) == (b))

# define FUNC_ARR_CON       short passed = 1; \
                            size_t i = 0; \
                            \
                            while (i < len) { \
                                if (NUM_EQUALS(a[i], b[i]) == 0) { \
                                    passed = 0; \
                                } \
                                i++; \
                            } \
                            add_test_to_env(init_new_test(ASSERT_ARR, passed));

# define FUNC_ARR_PRO(type)	    type a[], type b[], size_t len

void assert_arr_char(FUNC_ARR_PRO(char)) { FUNC_ARR_CON }
void assert_arr_short(FUNC_ARR_PRO(short)) { FUNC_ARR_CON }
void assert_arr_int(FUNC_ARR_PRO(int)) { FUNC_ARR_CON }
void assert_arr_long(FUNC_ARR_PRO(long)) { FUNC_ARR_CON }
void assert_arr_long_long(FUNC_ARR_PRO(long long)) { FUNC_ARR_CON }
void assert_arr_float(FUNC_ARR_PRO(float)) { FUNC_ARR_CON }
void assert_arr_double(FUNC_ARR_PRO(double)) { FUNC_ARR_CON }
void assert_arr_long_double(FUNC_ARR_PRO(long double)) { FUNC_ARR_CON }
void assert_arr_unsigned_char(FUNC_ARR_PRO(unsigned char)) { FUNC_ARR_CON }
void assert_arr_unsigned_short(FUNC_ARR_PRO(unsigned short)) { FUNC_ARR_CON }
void assert_arr_unsigned_int(FUNC_ARR_PRO(unsigned int)) { FUNC_ARR_CON }
void assert_arr_unsigned_long(FUNC_ARR_PRO(unsigned long)) { FUNC_ARR_CON }
void assert_arr_unsigned_long_long(FUNC_ARR_PRO(unsigned long long)) { FUNC_ARR_CON }

void 	assert_arr_str(char **s1, char **s2, size_t len) {
    short passed = 1;
    size_t i = 0;

    while (i < len) {
        if ((s1[i] == NULL) ^ (s2[i] == NULL)) {
            passed = 0;
        }
        else if (s1[i] == NULL) {
            continue ;
        }
        else if (strcmp(s1[i], s2[i])) {
            passed = 0;
        }
        i++;
    }
    add_test_to_env(init_new_test(ASSERT_ARR, passed));
}
