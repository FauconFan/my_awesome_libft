/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_filesystem.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:24:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 11:44:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_FILESYSTEM_H
# define F_FILESYSTEM_H

# include "libft.h"

# define BUFF_SIZE_GNL			25

typedef struct	s_env_gnl
{
	struct s_env_gnl	*next;
	char				**buff_prog;
	int					fd;
}				t_env_gnl;

int				ft_gnl(const int fd, char **line, t_env_gnl *env_gnl);
int				ft_gnl_c(const int fd, char **line,
					t_env_gnl *env_gnl, size_t buff_size_gnl);
int				ft_gnl_stdin(char **line);

t_env_gnl		*ft_init_env_gnl(void);
void			ft_free_env_gnl(t_env_gnl *head);
char			**find_buff_prog(t_env_gnl *head, int searched_fd);

char			*ft_get_content_file(
					char *file_path,
					size_t *size_file,
					char **errno_str);
char			*ft_get_content_file_fd(
					int fd,
					size_t *size_file,
					char **errno_str);
char			*ft_get_content_file_fd_nostat(
					int fd,
					size_t *size_file,
					char **errno_str);

void			ft_put_content_file(
					char *file_path,
					char *content,
					size_t len,
					char **errno_str);

#endif
