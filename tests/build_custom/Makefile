# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 13:14:13 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/29 18:02:12 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_BUILD_CUSTOM = ../../build_custom/
PATH_RENDU = ../../rendu/
RELATIVE_PATH_FORM_BUILD_CUSTOM = ../tests/build_custom/

FOLDER_NAME = "01_simpletest_putstr"

10 : 11 12 13 14 15 16

11 :
	make singletest_buildcustom FOLDER_NAME=11_simpletest_putstr/

12 :
	make singletest_buildcustom FOLDER_NAME=12_simpletest_putchar/

13 :
	make singletest_buildcustom FOLDER_NAME=13_simpletest_isalnum/

14 :
	make singletest_buildcustom FOLDER_NAME=14_simpletest_toupper/

15 :
	make singletest_buildcustom FOLDER_NAME=15_simpletest_logb/

16 :
	make singletest_buildcustom FOLDER_NAME=16_simpletest_memdel/

21 :
	make test_ok_buildcustom FOLDER_NAME=21_simple_compilable_printf/

test_ok_buildcustom :
	make -C $(PATH_BUILD_CUSTOM) PARAM=$(RELATIVE_PATH_FORM_BUILD_CUSTOM)$(FOLDER_NAME)
	cp -r $(PATH_RENDU) $(FOLDER_NAME)/libft
	sh ../scripts/build_custom.sh test_ok $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)/libft

singletest_buildcustom :
	make -C $(PATH_BUILD_CUSTOM) PARAM=$(RELATIVE_PATH_FORM_BUILD_CUSTOM)$(FOLDER_NAME)
	cp -r $(PATH_RENDU) $(FOLDER_NAME)/libft
	sh ../scripts/build_custom.sh simple_test $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)libft
