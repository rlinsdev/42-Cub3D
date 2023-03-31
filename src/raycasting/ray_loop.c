/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:04:51 by rlins             #+#    #+#             */
/*   Updated: 2023/03/31 11:33:34 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y);
static void	set_image_pixel(t_img *image, int x, int y, int color);
static void	setup_raycasting_info(int x, t_ray *ray, t_player *player);

/**
 * @brief
 *
 * @hint: fabs: This function returns the absolute value in double.
 * @param x
 * @param ray
 * @param player
 */
static void	setup_raycasting_info(int x, t_ray *ray, t_player *player)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

/**
 * @brief Calculate distance projected on camera direction (Euclidean distance
 * would give fisheye effect!)
 * @hint: line_height: Calculate height of line to draw on screen
 * @hint: Calculate lowest and highest pixel to fill in current stripe
 * @param ray Ray Structure
 * @param data Data Structure
 * @param player Player Structure
 */
static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{

	if (ray->hit_side == false)
		ray->wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->hit_side == false)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	calc_raycast(t_data *data)
{
	int	pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		setup_raycasting_info(pixel, &data->ray, &data->player);
		calc_dda(&data->ray, &data->player);
		perform_dda(data, &data->ray);
		calculate_line_height(&data->ray, data, &data->player);
		update_text_pixels(data, &data->texture_det, &data->ray, pixel);
		pixel++;
	}
	if (DEBUG_INFO)
		debug(data);
}

/**
 * @brief Responsible put the color in exact pixel. Each pixel will pass here
 * @hint: If we going to generate the minimap, we probably will use this
 * func.
 * @param image image structure
 * @param x X axis
 * @param y y axis
 * @param color integer color to put in pixel
 */
static void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

/**
 * @brief Responsible to read all pixel by pixel and draw the screen.
 * The first condition will draw the textures.
 * The second condition will draw the Ceiling/sky
 * The third condition will draw the floor/ground
 * @hint: If we go to implement the map, probably, the call will be here!
 * @param data Data Structure
 * @param image Image structure
 * @param x x coordinate in map array
 * @param y y coordinate in map array
 */
static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < HEIGHT / 2)
		set_image_pixel(image, x, y, data->texture_det.hex_ceiling);
	else if (y < HEIGHT -1)
		set_image_pixel(image, x, y, data->texture_det.hex_floor);
}

/**
 * @brief pass through all pixel
 *
 * @hint: mlx_put_image_to_window is the responsible to put image in screen.
 * If reallocated inside the loop, all draw will be slow / you can see the
 * screen generating...
 * @param data
 */
static void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, WIDTH, HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->view.mlx, data->view.win, image.img, 0, 0);
	mlx_destroy_image(data->view.mlx, image.img);
}

void	render_images(t_data *data)
{
	init_texture_pixels(data);
	calc_raycast(data);
	render_frame(data);
}

int	ray_loop(t_data *data)
{
	data->player.has_moved += move_player(data);
	if (data->player.has_moved == 0)
		return (0);
	render_images(data);
	return (SUCCESS);
}
