/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:14:16 by rlins             #+#    #+#             */
/*   Updated: 2023/03/31 11:36:52 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static bool	is_valid_pos_in_map(t_data *data, double x, double y);

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos_in_map(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos_in_map(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

/**
 * @brief This method will calculate if the axis X and Y keep inside the
 * map width and height. Will return true if is inside. false if is outside.
 * It will handle the limits player in map surrounded by '1's
 * @param data Data Structure
 * @param x axis X
 * @param y axis Y
 * @return boolean
 */
static bool	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map_det.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map_det.height -0.25)
		return (false);
	return (true);
}
