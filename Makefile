# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 16:27:58 by jpriou            #+#    #+#              #
#    Updated: 2018/08/24 22:03:34 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all
all:
	@ echo "Summary"
	@ echo ""
	@ echo "make libft"

.PHONY: libft
libft:
	@ make -C libft
	@ echo "the library is in libft folder."

.PHONY: fclean
fclean:
	@ make -C libft fclean

.PHONY: testall
testall:
	@ python3 .travis_gen.py
	@ ./.test_all.sh
