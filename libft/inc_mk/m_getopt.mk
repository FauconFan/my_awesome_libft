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
GETOPT_ARG_FOLDER = $(GETOPT_FOLDER)arg/
GETOPT_OPT_FOLDER = $(GETOPT_FOLDER)opt/
GETOPT_PARSING_FOLDER = $(GETOPT_FOLDER)parsing/
GETOPT_GETTERS_FOLDER = $(GETOPT_FOLDER)getters/
GETOPT_HELP_FOLDER = $(GETOPT_FOLDER)help/

SRC_ARG_GETOPT = \
				cli_arg.c \
				cli_res_array.c \
				cli_res_bool.c \
				cli_res_string.c \
				cli_get_arg_w_target.c \
				cli_arg_utils.c \
				cli_arg_gettype.c \

SRC_OPT_GETOPT = \
				cli_opt.c \
				cli_s_opt.c \
				cli_l_opt.c \
				cli_search_s_opt.c \
				cli_search_l_opt.c \

SRC_PARSING_GETOPT = \
				res_parser_finish.c \
				ft_cli_parse.c \
				ft_cli_parse2.c \
				ft_cmd_parse.c \

SRC_GETTERS_GETOPT = \
				ft_cli_getb.c \
				ft_cli_gets.c \
				ft_cli_geta.c \
				ft_cli_getstr_rc.c \

SRC_HELP_GETOPT = \
				handle_help_cli.c \
				handle_help_cmd.c \
				build_helper_properly.c \
				is_user_fault.c \

SRC_GETOPT = \
				add.c \
				cli_builder_parser.c \
				cli_parser.c \
				cmd_builder_parser.c \
				cmd_builder_parser_node.c \
				cmd_builder_parser_node2.c \
				cmd_parser.c \
				getopt.c \
				getopt_utils.c \
				getopt_cmd.c \

SRC += $(addprefix $(GETOPT_FOLDER), $(SRC_GETOPT))
SRC += $(addprefix $(GETOPT_ARG_FOLDER), $(SRC_ARG_GETOPT))
SRC += $(addprefix $(GETOPT_OPT_FOLDER), $(SRC_OPT_GETOPT))
SRC += $(addprefix $(GETOPT_PARSING_FOLDER), $(SRC_PARSING_GETOPT))
SRC += $(addprefix $(GETOPT_GETTERS_FOLDER), $(SRC_GETTERS_GETOPT))
SRC += $(addprefix $(GETOPT_HELP_FOLDER), $(SRC_HELP_GETOPT))
