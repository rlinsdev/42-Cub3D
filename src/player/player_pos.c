/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:47:01 by rlins             #+#    #+#             */
/*   Updated: 2023/04/04 01:42:19 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = old_x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);

	return (EXIT_SUCCESS);
}

int	rotate_player_rigth(t_data *d)
{
	rotate(&d->player.dir_x, &d->player.dir_y, ROTSPEED);
	rotate(&d->player.plane_x, &d->player.plane_y, ROTSPEED);
	return (EXIT_SUCCESS);
}

int	rotate_player_left(t_data *d)
{
	rotate(&d->player.dir_x, &d->player.dir_y, -ROTSPEED);
	rotate(&d->player.plane_x, &d->player.plane_y, -ROTSPEED);
	return (EXIT_SUCCESS);
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
	else if (p->dir == 'W')
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
