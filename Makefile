# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 16:27:58 by jpriou            #+#    #+#              #
#    Updated: 2018/06/27 08:52:22 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft ctestcom build_custom fclean

PARAM = ""

all:
	echo "No default rules is provided"
	echo ""
	echo "make libft_library"

libft :
	@make -C libft
	@echo "the library is in libft folder."

ctestcom :
	@make -C ctestcom

build_custom :
	@test "$(PARAM)" || (echo "set the PARAM argument" && exit 1)
	@make -C build_custom PARAM=../"$(PARAM)"

fclean:
	@make -C libft fclean
	@make -C ctestcom fclean
