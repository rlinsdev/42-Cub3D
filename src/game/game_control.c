/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:10:21 by lpires-n          #+#    #+#             */
/*   Updated: 2023/04/13 16:16:49 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_player_direction(t_player *p)
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
	return (EXIT_SUCCESS);
}

int	rotate(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = old_x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
	return (EXIT_SUCCESS);
}

int	check_collision(t_data *d, double x, double y)
{
	if (x < 0 || x >= d->map_det.width ||
		y < 0 || y >= d->map_det.height ||
		d->map[(int)y][(int)x] == C_WALL)
	{
		return (true);
	}
	return (false);
}

int	move(t_data *d, double dx, double dy)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = d->player.pos_x + dx * MOVE_SPEED;
	new_pos_y = d->player.pos_y + dy * MOVE_SPEED;

	if (check_collision(d, new_pos_x, new_pos_y))
		return (EXIT_FAILURE);
	if (dx != 0 && dy != 0)
	{
		if (check_collision(d, new_pos_x + dx * 0.1 , d->player.pos_y) ||
			check_collision(d, d->player.pos_x, new_pos_y + dy *  0.1 ))
			return (EXIT_FAILURE);
	}
	d->player.pos_x = new_pos_x;
	d->player.pos_y = new_pos_y;
	return (EXIT_SUCCESS);
}
