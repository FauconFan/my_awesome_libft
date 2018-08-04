/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:07:29 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 18:21:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(void)
{
	t_env_gnl		*env_gnl;
	char			*str;

	env_gnl = init_env_gnl();
	get_next_line(0, &str, 0);
	get_next_line(0, 0, env_gnl);
	get_next_line(-1, &str, env_gnl);
	free_env_gnl(env_gnl);
	env_gnl = init_env_gnl();
	free_env_gnl(env_gnl);
	env_gnl = init_env_gnl();
	free_env_gnl(env_gnl);
	env_gnl = init_env_gnl();
	free_env_gnl(env_gnl);
	env_gnl = init_env_gnl();
	free_env_gnl(env_gnl);
	return (0);
}
