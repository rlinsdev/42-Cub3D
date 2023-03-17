/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/17 03:37:34 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


void init_ray(t_ray *player)
{
	player->pos[0] = 5;
	player->pos[1] = 5;
	player->dir[0] = -1;
	player->dir[1] = 0;
	player->plane[0] = 0;
	player->plane[1] = 0.66;
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	init_ray(&data->ray);

}
