/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:37:54 by rlins             #+#    #+#             */
/*   Updated: 2023/04/04 01:19:22 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVE_SPEED;

	if (data->map[(int)new_y][(int)new_x] == '1')
		return (0);

	data->player.pos_x = new_x;
	data->player.pos_y = new_y;

	return (1);
}

int	move_player_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVE_SPEED;

	if (data->map[(int)new_y][(int)new_x] == '1')
		return (0);

	data->player.pos_x = new_x;
	data->player.pos_y = new_y;

	return (1);
}

int	move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVE_SPEED;
	if (data->map[(int)new_y][(int)new_x] == '1')
		return (0);
	data->player.pos_x = new_x;
	data->player.pos_y = new_y;

	return (1);
}

int	move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVE_SPEED;
	if (data->map[(int)new_y][(int)new_x] == '1')
		return (0);
	data->player.pos_x = new_x;
	data->player.pos_y = new_y;
	return (1);
}
