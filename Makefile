# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 16:27:58 by jpriou            #+#    #+#              #
#    Updated: 2018/08/04 16:00:20 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft ctestcom build_custom fclean

PARAM = ""

all:
	@echo "No default rules is provided"
	@echo ""
	@echo "make libft_library"
	@echo "make build_custom"

libft :
	@make -C libft
	@echo "the library is in libft folder."

build_custom :
	@make -C build_custom

fclean:
	@make -C libft fclean
	@make -C build_custom fclean
	@rm -rf rendu

testall:
	./scripts/test_all.sh
