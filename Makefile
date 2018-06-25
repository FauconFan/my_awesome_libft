# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 16:27:58 by jpriou            #+#    #+#              #
#    Updated: 2018/06/25 17:21:52 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARAM = ""

all:
	echo "No default rules is provided"

libft_library :
	@make -C libft
	@echo "the library is in libft folder."

ctestcom_program :
	@make -C ctestcom

build_custom_project :
	@test "$(PARAM)" || (echo "set the PARAM argument" && exit 1)
	@make -C build_custom PARAM=../"$(PARAM)"

fclean:
	@make -C libft fclean
	@make -C ctestcom fclean
