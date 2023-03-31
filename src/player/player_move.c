/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:37:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 22:17:43 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Responsible to move forward the player. Will calculate the new
 * position of player
 * @param data Structure
 * @return int
 */
static int	move_player_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVE_SPEED;
	return (validate_move(data, new_x, new_y));
}

/**
 * @brief Responsible to move backward the player. Will calculate the new
 * position of player
 * @param data Structure
 * @return int
 */
static int	move_player_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVE_SPEED;
	return (validate_move(data, new_x, new_y));
}

/**
 * @brief Responsible to move left the player. Will calculate the new
 * position of player
 * @param data Structure
 * @return int
 */
static int	move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVE_SPEED;
	return (validate_move(data, new_x, new_y));
}

/**
 * @brief Responsible to move right the player. Will calculate the new
 * position of player
 * @param data Structure
 * @return int
 */
static int	move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVE_SPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_player_forward(data);
	if (data->player.move_y == -1)
		moved += move_player_backward(data);
	if (data->player.move_x == -1)
		moved += move_player_left(data);
	if (data->player.move_x == 1)
		moved += move_player_right(data);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}



