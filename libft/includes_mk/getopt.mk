# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/03 16:02:20 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GETOPT_FOLDER = $(SRC_FOLDER)getopt/

SRC_GETOPT = \
				arg/cli_arg.c \
				arg/cli_res_array.c \
				arg/cli_res_bool.c \
				arg/cli_res_string.c \
				opt/cli_opt.c \
				parsing/res_parser_finish.c \
				getters/ft_cli_getb.c \
				getters/ft_cli_gets.c \
				getters/ft_cli_geta.c \
				add_bool.c \
				cli_parser.c \
				cli_res_parser.c \
				cli_utils.c \

SRC += $(addprefix $(GETOPT_FOLDER), $(SRC_GETOPT))
