/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lpires-n          #+#    #+#             */
/*   Updated: 2023/04/10 14:54:13 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Will destroy all mlx windows and free all data.
 * @param data Data structure
 * @return int
 */
int	close_hook(t_data *d)
{
	mlx_destroy_image(d->view.mlx, d->view.screen.img);
	mlx_destroy_window(d->view.mlx, d->view.win);
	mlx_destroy_display(d->view.mlx);
	free_data(d);
	free(d->view.mlx);
	exit(SUCCESS);
}

/**
 * @brief Handle all key press used in game.
 * @param keycode Key code pressed
 * @param data Data structure
 * @return int
 */
int	key_hook(int key, t_data *d)
{
	if (key == XK_Escape)
		close_hook(d);
	if (key == XK_w)
		move(d, d->player.dir_x, d->player.dir_y);
	if (key == XK_s)
		move(d, -d->player.dir_x, -d->player.dir_y);
	if (key == XK_a)
		move(d, -d->player.plane_x, -d->player.plane_y);
	if (key == XK_d)
		move(d, d->player.plane_x, d->player.plane_y);
	if (key == XK_Left)
	{
		rotate(&d->player.dir_x, &d->player.dir_y, -ROTSPEED);
		rotate(&d->player.plane_x, &d->player.plane_y, -ROTSPEED);
	}
	if (key == XK_Right)
	{
		rotate(&d->player.dir_x, &d->player.dir_y, ROTSPEED);
		rotate(&d->player.plane_x, &d->player.plane_y, ROTSPEED);
	}
	return (SUCCESS);
}

int	starting_game(t_data *d)
{
	mlx_hook(d->view.win, DestroyNotify, StructureNotifyMask, close_hook, d);
	mlx_hook(d->view.win, KeyPress, KeyPressMask, key_hook, d);
	mlx_loop_hook(d->view.mlx, render_images, d);
	return (SUCCESS);
}
