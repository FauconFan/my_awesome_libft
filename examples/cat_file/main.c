/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:40:39 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/16 09:13:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

static int cat(char *filepath) {
	t_env_gnl	*head;
	char		*buff;
	int			fd;
	int			ret;

	ret = 0;
	head = ft_init_env_gnl();
	fd = open(filepath, O_RDONLY);
	if (fd >= 0) {
		while (ft_gnl(fd, &buff, head) != 0)
		{
			ft_putendl(buff);
			free(buff);
		}
		close(fd);
	}
	else {
		ft_printf("%s is not a correct path file\n", filepath);
		ret = 2;
	}
	ft_free_env_gnl(head);
	return ret;
}

int main(int argc, char *argv[]) {
	int ret;

	ret = 0;
	if (argc != 2) {
		ft_printf("./bin/cat_file [path_file]\n");
		ret = 1;
	}
	else {
		ret = cat(argv[1]);
	}
	return ret;
}
