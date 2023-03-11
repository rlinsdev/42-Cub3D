/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:21:54 by rlins             #+#    #+#             */
/*   Updated: 2023/03/11 10:37:36 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_map_det(t_map_det *map_det);
static void	init_texture_det(t_texture_det  *texture_det);

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	init_map_det(&data->map_det);
	// TODO: Provavelmente haverá um initialize person too
	init_texture_det(&data->texture_det);
}

/**
 * @brief Initialize Texture Details structure
 * TODO: Futuramente será substituído pela auto-inicialização de estrutrura.
 * @param texture_det
 */
static void	init_texture_det(t_texture_det  *text_det)
{
	text_det->north = NULL;
	text_det->south = NULL;
	text_det->west = NULL;
	text_det->east = NULL;
	text_det->floor = 0;
	text_det->ceiling = 0;
}

/**
 * @brief Initialize the map detail structure.
 * @param map_det Map Detail Structure by ref
 */
static void	init_map_det(t_map_det *map_det)
{
	map_det->fd = 0;
	map_det->lines_file = 0;
	map_det->path = NULL;
	map_det->file = NULL;
	map_det->width = 0;
	map_det->height = 0;
}
