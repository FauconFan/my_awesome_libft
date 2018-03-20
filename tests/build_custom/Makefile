# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 13:14:13 by fauconfan         #+#    #+#              #
#    Updated: 2018/03/20 22:21:01 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_BUILD_CUSTOM = ../../build_custom/
PATH_RENDU = ../../rendu/
RELATIVE_PATH_FROM_BUILD_CUSTOM = ../tests/build_custom/

FOLDER_NAME = ""

0 : 10 20 30

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

20 : 21 22 23 24

21 :
	make test_ok_buildcustom FOLDER_NAME=21_simple_compilable_printf/

22 :
	make test_ok_buildcustom FOLDER_NAME=22_simple_compilable_str_is_alnum/

23 :
	make test_ok_buildcustom FOLDER_NAME=23_simple_compilable_strsplit/

24 :
	make test_ok_buildcustom FOLDER_NAME=24_simple_compilable_convertbase/

30 : 31 32 33 34 35

31 :
	make test_ok_buildcustom FOLDER_NAME=31_miscellaneous/

32 :
	make test_ok_buildcustom FOLDER_NAME=32_miscellaneous/

33 :
	make test_ok_buildcustom FOLDER_NAME=33_miscellaneous/

34 :
	make test_ok_buildcustom FOLDER_NAME=34_miscellaneous/

35 :
	make test_ok_buildcustom FOLDER_NAME=35_miscellaneous/

test_ok_buildcustom :
	make -C $(PATH_BUILD_CUSTOM) PARAM=$(RELATIVE_PATH_FROM_BUILD_CUSTOM)$(FOLDER_NAME)
	cp -r $(PATH_RENDU) $(FOLDER_NAME)libft
	sh ../build_custom.sh test_ok $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)libft

singletest_buildcustom :
	make -C $(PATH_BUILD_CUSTOM) PARAM=$(RELATIVE_PATH_FROM_BUILD_CUSTOM)$(FOLDER_NAME)
	cp -r $(PATH_RENDU) $(FOLDER_NAME)libft
	sh ../build_custom.sh simple_test $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)libft
