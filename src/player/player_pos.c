/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:47:01 by rlins             #+#    #+#             */
/*   Updated: 2023/04/04 01:23:53 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int rotate_player_left (t_data *d)
{
	double old;

	old = d->player.dir_x;
	d->player.dir_x = d->player.dir_x * cos(-ROTSPEED) - d->player.dir_y * sin(-ROTSPEED);
	d->player.dir_y = old * sin(-ROTSPEED) + d->player.dir_y * cos(-ROTSPEED);
	old = d->player.plane_x;
	d->player.plane_x = d->player.plane_x * cos(-ROTSPEED) - d->player.plane_y * sin(-ROTSPEED);
	d->player.plane_y = old * sin(-ROTSPEED) + d->player.plane_y * cos(-ROTSPEED);
	return (1);
}

int rotate_player_rigth(t_data *d)
{
	double old;

	old = d->player.dir_x;
	d->player.dir_x = d->player.dir_x * cos(ROTSPEED) - d->player.dir_y * sin(ROTSPEED);
	d->player.dir_y = old * sin(ROTSPEED) + d->player.dir_y * cos(ROTSPEED);
	old = d->player.plane_x;
	d->player.plane_x = d->player.plane_x * cos(ROTSPEED) - d->player.plane_y * sin(ROTSPEED);
	d->player.plane_y = old * sin(ROTSPEED) + d->player.plane_y * cos(ROTSPEED);
	return (1);
}


void	set_player_direction(t_player *p)
{
	if (p->dir == 'S')
	{
		p->dir_y = 1;
		p->plane_x = -0.66;
	}
	else if (p->dir == 'N')
	{
		p->dir_y = -1;
		p->plane_x = 0.66;
	}
	if (p->dir == 'W')
	{
		p->dir_x = -1;
		p->plane_y = -0.66;
	}
	else if (p->dir == 'E')
	{
		p->dir_x = 1;
		p->plane_y = 0.66;
	}
}
