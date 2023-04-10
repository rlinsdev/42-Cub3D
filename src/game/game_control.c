/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:10:21 by lpires-n          #+#    #+#             */
/*   Updated: 2023/04/10 17:24:21 by lpires-n         ###   ########.fr       */
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

int	move(t_data *d, double dx, double dy)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = d->player.pos_x + dx * MOVE_SPEED;
	new_pos_y = d->player.pos_y + dy * MOVE_SPEED;
	if (d->map[(int)(new_pos_y + dy * MOVE_SPEED)] \
	[(int)(new_pos_x + dx * MOVE_SPEED)] == C_WALL)
	{
		return (EXIT_FAILURE);
	}
	d->player.pos_x = new_pos_x;
	d->player.pos_y = new_pos_y;
	return (EXIT_SUCCESS);
}
