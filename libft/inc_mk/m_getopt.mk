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

GETOPT_FOLDER = $(SRC_FOLDER)m_getopt/

SRC_GETOPT = \
				arg/cli_arg.c \
				arg/cli_res_array.c \
				arg/cli_res_bool.c \
				arg/cli_res_string.c \
				arg/cli_get_arg_w_target.c \
				arg/cli_arg_utils.c \
				arg/cli_arg_gettype.c \
				opt/cli_opt.c \
				opt/cli_s_opt.c \
				opt/cli_l_opt.c \
				opt/cli_search_s_opt.c \
				opt/cli_search_l_opt.c \
				parsing/res_parser_finish.c \
				parsing/ft_cli_parse.c \
				parsing/ft_cli_parse2.c \
				parsing/ft_cmd_parse.c \
				getters/ft_cli_getb.c \
				getters/ft_cli_gets.c \
				getters/ft_cli_geta.c \
				getters/ft_cli_getstr_rc.c \
				help/handle_help_cli.c \
				help/handle_help_cmd.c \
				help/build_helper_properly.c \
				help/is_user_fault.c \
				add.c \
				cli_builder_parser.c \
				cli_parser.c \
				cmd_builder_parser.c \
				cmd_builder_parser_node.c \
				cmd_parser.c \
				getopt.c

SRC += $(addprefix $(GETOPT_FOLDER), $(SRC_GETOPT))
