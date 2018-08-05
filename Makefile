# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 16:27:58 by jpriou            #+#    #+#              #
#    Updated: 2018/08/05 13:09:52 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft ctestcom fclean

all:
	@echo "No default rules is provided"
	@echo ""
	@echo "make libft_library"

libft :
	@make -C libft
	@echo "the library is in libft folder."

fclean:
	@make -C libft fclean
	@rm -rf rendu

testall:
	./scripts/test_all.sh
