/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 12:32:44 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void init_ray(t_ray *r, t_data *data);

/**
 * @brief Initialize Ray values
 * @param r
 */

//TODO:L
static void init_ray(t_ray *r, t_data *data)
{
	// r->dir[0] = 0;
	// r->dir[1] = 0;
	// r->plane[0] = 0;
	// r->plane[1] = 0;
	// r->speed = 0.1;
}

//TODO:L
void	set_player_direction(t_player *p)
{
	// if (r->dir_char == 'N')
	// {
	// 	r->dir[0] = -1;
	// 	r->plane[1] = -0.66;
	// }
	// else if (r->dir_char == 'S')
	// {
	// 	r->dir[0] = 1;
	// 	r->plane[1] = 0.66;
	// }
	// else if (r->dir_char == 'E')
	// {
	// 	r->dir[1] = 1;
	// 	r->plane[0] = -0.66;
	// }
	// else if (r->dir_char == 'W')
	// {
	// 	r->dir[1] = -1;
	// 	r->plane[0] = 0.66;
	// }
	if (p->dir == 'S')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
	else if (p->dir == 'N')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	if (p->dir == 'W')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
	else if (p->dir == 'E')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	init_ray(&data->ray, data);
}
