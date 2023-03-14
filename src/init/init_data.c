/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/14 03:42:45 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->player.pos_x = 22;
	data->player.pos_y = 12;
	data->player.dir_x = -1;
	data->player.dir_y = 0;
	data->player.plane_y = 0.66;
	data->view.screen_height = HEIGHT;
	data->view.screen_width = WIDTH;
}
