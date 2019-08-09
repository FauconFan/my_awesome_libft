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

FILESYSTEM_FOLDER = $(SRC_FOLDER)f_filesystem/

SRC_FILESYSTEM = \
					utils/env_gnl.c \
					ft_get_content_file_fd_nostat.c \
					ft_get_content_file_fd.c \
					ft_get_content_file_nostat.c \
					ft_get_content_file.c \
					ft_put_content_file.c \
					ft_gnl.c \

SRC += $(addprefix $(FILESYSTEM_FOLDER), $(SRC_FILESYSTEM))
