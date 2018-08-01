# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 16:51:26 by jpriou            #+#    #+#              #
#    Updated: 2018/08/01 17:32:33 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FOLDERS := $(shell ls -d */ | grep -v bin | sed -e "s/\///g")
BIN := $(addprefix bin/, $(FOLDERS))

GWW := gcc -Wall -Wextra -Werror

LIBFT_DIR := ../libft
LIBFT := $(LIBFT_DIR)/libft.a

all: bin $(LIBFT) $(BIN)

bin:
	mkdir bin

$(LIBFT):
	make -C $(LIBFT_DIR)

bin/%: %
	@printf "Compiling %s\\n" "$@"
	@$(GWW) $(shell find $? -name "*.c") -o $@ -l ft -L $(LIBFT_DIR) -I $(LIBFT_DIR)

clean:
	rm -rf $(BIN)
	rm -rf bin

re: clean all
