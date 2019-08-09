# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2019/01/19 09:09:06 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VERSION_GCC_DOCKER = latest

TEST_CMD = make

.PHONY: gcc
gcc:
	make -C . fclean
	docker run -d \
			--name build_libft_gcc \
			--volume `pwd`:/libft_repo \
			-w /libft_repo \
			gcc:$(VERSION_GCC_DOCKER) \
			tail -f /dev/null
	docker exec build_libft_gcc gcc --version
	docker exec build_libft_gcc $(TEST_CMD)
	docker exec build_libft_gcc make fclean
	docker stop build_libft_gcc
	docker rm build_libft_gcc

.PHONY: clang
clang:
	make -C . fclean
	docker run -d \
			--name build_libft_clang \
			--volume `pwd`:/libft_repo \
			-w /libft_repo \
			debian \
			tail -f /dev/null
	docker exec build_libft_clang apt-get update
	docker exec build_libft_clang apt-get install -y --no-install-recommends clang make
	docker exec build_libft_clang apt-get clean
	docker exec build_libft_clang rm -rf /var/lib/apt/lists/*
	docker exec build_libft_clang $(TEST_CMD) CC=clang
	docker exec build_libft_clang make fclean
	docker stop build_libft_clang
	docker rm build_libft_clang