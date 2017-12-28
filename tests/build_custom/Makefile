# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 13:14:13 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/28 09:12:50 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_BUILD_CUSTOM = ../../build_custom/
PATH_RENDU = ../../rendu/
RELATIVE_PATH_FORM_BUILD_CUSTOM = ../tests/build_custom/

FOLDER_NAME = "01_simpletest_putstr"

01 :
	make singletest_buildcustom FOLDER_NAME=01_simpletest_putstr/

02 :
	make singletest_buildcustom FOLDER_NAME=02_simpletest_putchar/

21 :
	make test_tg_buildcustom FOLDER_NAME=21_simple_compilable_printf/

test_tg_buildcustom :
	make -C $(PATH_BUILD_CUSTOM) PARAM=$(RELATIVE_PATH_FORM_BUILD_CUSTOM)$(FOLDER_NAME)
	cp -r $(PATH_RENDU) $(FOLDER_NAME)/libft
	sh ../scripts/build_custom.sh test_tg $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)/libft

singletest_buildcustom :
	make -C $(PATH_BUILD_CUSTOM) PARAM=$(RELATIVE_PATH_FORM_BUILD_CUSTOM)$(FOLDER_NAME)
	cp -r $(PATH_RENDU) $(FOLDER_NAME)/libft
	sh ../scripts/build_custom.sh simple_test $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)/libft
