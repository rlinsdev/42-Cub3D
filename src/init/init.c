/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/07 12:07:06 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void init_map_det(t_map_det *map_det);

// TODO: Remover?
int	start(int argc, char **argv)
{
	printf("olá mundo\n");
	return (0);
}

void init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	init_map_det(&data->map_det);
	// TODO: Provavelmente haverá um initialize person too
}

/**
 * @brief Initialize the map detail structure.
 * @param map_det Map Detail Structure by ref
 */
static void init_map_det(t_map_det *map_det)
{
	map_det->fd = 0;
	map_det->lines_count = 0;
	map_det->path = NULL;
	map_det->file = NULL;
	map_det->width = 0;
	map_det->height = 0;
}
