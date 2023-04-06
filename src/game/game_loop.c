/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lucas             #+#    #+#             */
/*   Updated: 2023/04/06 17:09:33 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_hook_close(t_data *d)
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
int	handle_hook_key_press(int key, t_data *d)
{
	if (key == XK_Escape)
		handle_hook_close(d);
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

int	handle_hook_mouse_move(int x, int y, t_data *d)
{
	(void)y;
	if (x < WIDTH / 2)
	{
		rotate(&d->player.dir_x, &d->player.dir_y, -ROTSPEED);
		rotate(&d->player.plane_x, &d->player.plane_y, -ROTSPEED);
		mlx_mouse_move(d->view.mlx, d->view.win, WIDTH / 2, HEIGHT / 2);
	}
	else if (x > WIDTH / 2)
	{
		rotate(&d->player.dir_x, &d->player.dir_y, ROTSPEED);
		rotate(&d->player.plane_x, &d->player.plane_y, ROTSPEED);
		mlx_mouse_move(d->view.mlx, d->view.win, WIDTH / 2, HEIGHT / 2);
	}
	return (SUCCESS);
}

int	starting_game(t_data *d)
{
	mlx_hook(d->view.win, 17, 1L << 17, handle_hook_close, d);
	mlx_hook(d->view.win, 2, 1L << 0, handle_hook_key_press, d);
	mlx_hook(d->view.win, 6, 1L << 6, handle_hook_mouse_move, d);
	mlx_loop_hook(d->view.mlx, render_images, d);
	return (SUCCESS);
}
