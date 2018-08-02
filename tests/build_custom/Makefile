# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 13:14:13 by fauconfa          #+#    #+#              #
#    Updated: 2018/08/02 20:44:23 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_BC = ../../build_custom
PATH_RENDU = ../../rendu/
RELATIVE_PATH_FROM_BC = ../tests/build_custom/

FOLDER_NAME = ""

all : 10 20 30 40 50

10 : 11 12 13 14 15 16

20 : 21 22 23 24

30 : 31 32 33 34 35

40 : 41 42 43 44 45

50 : 51

11 :
	make singlefile_buildcustom FOLDER_NAME=11_simpletest_putstr/

12 :
	make singlefile_buildcustom FOLDER_NAME=12_simpletest_putchar/

13 :
	make singlefile_buildcustom FOLDER_NAME=13_simpletest_isalnum/

14 :
	make singlefile_buildcustom FOLDER_NAME=14_simpletest_toupper/

15 :
	make singlefile_buildcustom FOLDER_NAME=15_simpletest_logb/

16 :
	make singlefile_buildcustom FOLDER_NAME=16_simpletest_memdel/

21 :
	make test_ok_buildcustom FOLDER_NAME=21_simple_compilable_printf/

22 :
	make test_ok_buildcustom FOLDER_NAME=22_simple_compilable_str_is_alnum/

23 :
	make test_ok_buildcustom FOLDER_NAME=23_simple_compilable_strsplit/

24 :
	make test_ok_buildcustom FOLDER_NAME=24_simple_compilable_convertbase/

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

41:
	make test_ok_on_file_buildcustom FOLDER_NAME=41_miscellaneous_on_file/

42:
	make test_ok_on_file_buildcustom FOLDER_NAME=42_miscellaneous_on_file/

43:
	make test_ok_on_file_buildcustom FOLDER_NAME=43_miscellaneous_on_file/

44:
	make test_ok_on_file_buildcustom FOLDER_NAME=44_miscellaneous_on_file/

45:
	make test_ok_on_file_buildcustom FOLDER_NAME=45_miscellaneous_on_file/

51 :
	make test_ok_buildcustom FOLDER_NAME=51_mathsimple/

52 :
	make test_ok_buildcustom FOLDER_NAME=52_mathsimple/

test_ok_buildcustom :
	make -C $(PATH_BC) run PARAM=$(RELATIVE_PATH_FROM_BC)$(FOLDER_NAME)
	cp -r $(PATH_RENDU) $(FOLDER_NAME)libft
	sh ./build_custom.sh test_ok $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)libft

test_ok_on_file_buildcustom:
	make -C $(PATH_BC) run PARAM=$(RELATIVE_PATH_FROM_BC)$(FOLDER_NAME)main.c
	cp -r $(PATH_RENDU) $(FOLDER_NAME)libft
	sh ./build_custom.sh test_ok $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)libft

singlefile_buildcustom :
	make -C $(PATH_BC) run PARAM=$(RELATIVE_PATH_FROM_BC)$(FOLDER_NAME)
	cp -r $(PATH_RENDU) $(FOLDER_NAME)libft
	sh ./build_custom.sh simple_file_test $(FOLDER_NAME)
	rm -rf $(PATH_RENDU)
	rm -rf $(FOLDER_NAME)libft
