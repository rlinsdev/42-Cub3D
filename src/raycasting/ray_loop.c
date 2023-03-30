/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:04:51 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 18:38:47 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y);
static void	render_raycast(t_data *data);

// //TODO:L Ver se precisa deste código mesmo
// void	init_ray(t_ray *ray)
// {
// 	// ray->camera_x = 0;
// 	// ray->dir_x = 0;
// 	// ray->dir_y = 0;
// 	// ray->map_x = 0;
// 	// ray->map_y = 0;
// 	// ray->step_x = 0;
// 	// ray->step_y = 0;
// 	// ray->side_dist_x = 0;
// 	// ray->side_dist_y = 0;
// 	// ray->delta_dist_x = 0;
// 	// ray->delta_dist_y = 0;
// 	// ray->wall_dist = 0;
// 	// ray->wall_x = 0;
// 	// ray->hit_side = false; //TODO:L Acabei de transformar em bool aqui
// 	// ray->line_height = 0;
// 	// ray->draw_start = 0;
// 	// ray->draw_end = 0;
// }
//TODO:L
//TODO:L Trocar o nome de Init pra SetUp ou algo assim

/**
 * @brief
 *
 * fabs: This function returns the absolute value in double.
 * @param x
 * @param ray
 * @param player
 */
static void	init_raycasting_info(int x, t_ray *ray, t_player *player)
{
	// init_ray(ray);
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}


/*
- We implement the DDA algorithm -> the loop will increment 1 square
-   until we hit a wall
- If the sidedistx < sidedisty, x is the closest point from the ray
*/
//TODO:L
static void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		// **//jump to next map square, either in x-direction, or in y-direction
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->hit_side = false;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->hit_side = true;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->map_det.height - 0.25
			|| ray->map_x > data->map_det.width - 1.25)
			break ;
		// **//Check if ray has hit a wall
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}
//TODO:L
static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	// **//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if (ray->hit_side == false)
		ray->wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_dist = (ray->side_dist_y - ray->delta_dist_y);
		// **//Calculate height of line to draw on screen
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	// **//calculate lowest and highest pixel to fill in current stripe
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
	t_ray	ray;
	t_player player;

	pixel = 0;
	ray = data->ray;
	player = data->player;
	while (pixel < WIDTH)
	{
		init_raycasting_info(pixel, &ray, &player);
		calc_dda(&ray, &player);
		perform_dda(data, &ray);
		calculate_line_height(&ray, data, &player);
		update_text_pixels(data, &data->texture_det, &ray, pixel);
		pixel++;
	}
}
//TODO:L
void	set_image_pixel(t_img *image, int x, int y, int color)
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
 * Important: If we go to implement the map, probably, the call will be here!
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
 * @brief
 *
 * Important: mlx_put_image_to_window is the responsible to put image in screen.
 * If reallocated inside the loop, all draw will be slow
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

/**
 * @brief //TODO:L
 *
 * @param data
 */
static void	render_raycast(t_data *data)
{
	init_texture_pixels(data);
	// init_ray(&data->ray);
	calc_raycast(data);
	render_frame(data);
}

void	render_images(t_data *data)
{
	render_raycast(data);
}

int	ray_loop(t_data *data)
{
	data->player.has_moved += move_player(data);
	if (data->player.has_moved == 0)
		return (0);
	render_images(data);
	return (SUCCESS);
}
