/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:47:01 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 16:50:32 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static int	rotate_left_right(t_data *data, double rot_speed);

int	rotate_player(t_data *data, double rot_dir)
{
	int		moved;
	double	rot_speed;

	moved = 0;
	rot_speed = ROTSPEED * rot_dir;
	moved += rotate_left_right(data, rot_speed);
	return (moved);
}

/**
 * @brief //TODO:L dOCUMENTAR. ENTRA QUANDO ROATCIONA SÓ DO LEFT PRO RIGHT??
 *
 * @param data
 * @param rot_speed
 * @return int
 */
static int	rotate_left_right(t_data *data, double rot_speed)
{
	t_player	*p;
	double		tmp_x;

	p = &data->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = tmp_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = tmp_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
	return (1);
}
