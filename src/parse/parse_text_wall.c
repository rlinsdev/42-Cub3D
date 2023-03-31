/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:23:30 by rlins             #+#    #+#             */
/*   Updated: 2023/03/31 10:38:02 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	get_texture_index(t_data *data, t_ray *ray);

void	init_texture_pixels(t_data *data)
{
	int	i;

	if (data->texture_pixels)
		free_array_gen((void **)data->texture_pixels);
	data->texture_pixels = ft_calloc(HEIGHT + 1, sizeof * data->texture_pixels);
	if (!data->texture_pixels)
		exit_and_free(data, error_msg(ERR_MALC, 23));
	i = 0;
	while (i < HEIGHT)
	{
		data->texture_pixels[i] = ft_calloc(WIDTH + 1,
				sizeof * data->texture_pixels);
		if (!data->texture_pixels[i])
			exit_and_free(data, error_msg(ERR_MALC, 24));
		i++;
	}
}

/**
 * @brief Responsible to update the index of texture in current pixel.
 * This calculation is based in the ray direction and if the ray hit the wall.
 * @param data Dat aStructure
 * @param ray Ray structure
 */
static void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->hit_side == false)
	{
		if (ray->dir_x < 0)
			data->texture_det.index = WEST;
		else
			data->texture_det.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texture_det.index = SOUTH;
		else
			data->texture_det.index = NORTH;
	}
}

void	update_text_pixels(t_data *data, t_texture_det *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->hit_side == false && ray->dir_x < 0) || (ray->hit_side == true && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}


static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->texture_det.size * data->texture_det.size);
	if (!buffer)
		exit_and_free(data, error_msg(ERR_MALC, 25));
	y = 0;
	while (y < data->texture_det.size)
	{
		x = 0;
		while (x < data->texture_det.size)
		{
			buffer[y * data->texture_det.size + x]
				= tmp.addr[y * data->texture_det.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->view.mlx, tmp.img);
	return (buffer);
}
// //TODO:L Precisa disto mesmo?
// void	init_texinfo(t_texture_det *textures)
// {
// 	textures->north = NULL;
// 	textures->south = NULL;
// 	textures->west = NULL;
// 	textures->east = NULL;
// 	textures->floor = 0;
// 	textures->ceiling = 0;
// 	// textures->hex_floor = 0x0;
// 	// textures->hex_ceiling = 0x0;
// 	textures->size = TEX_SIZE;
// 	textures->step = 0.0;
// 	textures->pos = 0.0;
// 	textures->x = 0;
// 	textures->y = 0;
// }


void	setup_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		exit_and_free(data, error_msg(ERR_MALC, 26));
	data->textures[NORTH] = xpm_to_img(data, data->texture_det.north);
	data->textures[SOUTH] = xpm_to_img(data, data->texture_det.south);
	data->textures[EAST] = xpm_to_img(data, data->texture_det.east);
	data->textures[WEST] = xpm_to_img(data, data->texture_det.west);
	data->texture_det.size = TEX_SIZE;
}

