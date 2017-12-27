# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 13:14:13 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/27 14:42:03 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_BUILD_CUSTOM = ../../build_custom/
PATH_RENDU = ../../rendu/
RELATIVE_PATH_FORM_BUILD_CUSTOM = ../tests/build_custom/

00 :
	make -C $(PATH_BUILD_CUSTOM) PARAM=$(RELATIVE_PATH_FORM_BUILD_CUSTOM)00_simpletest_putstr
	cp -r $(PATH_RENDU) 00_simpletest_putstr/libft
	sh ../scripts/build_custom.sh simple_test 00_simpletest_putstr
	rm -rf $(PATH_RENDU)
	rm -rf 00_simpletest_putstr/libft
