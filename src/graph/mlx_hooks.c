/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lucas             #+#    #+#             */
/*   Updated: 2023/03/30 11:39:33 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_hook_close(t_data *data)
{
	mlx_destroy_image(data->view.mlx, data->view.screen.img);
	mlx_destroy_window(data->view.mlx, data->view.win);

	mlx_destroy_display(data->view.mlx);

	free_data(data);
	free(data->view.mlx);
	exit(SUCCESS);
}

//TODO:L
int	handle_hook_key_press(int keycode, t_data *data)
{
	// if (keycode == A_KEY_CONST)
	// 	ray_move_left(&data->ray, data->map);
	// else if (keycode == D_KEY_CONST)
	// 	ray_move_right(&data->ray, data->map);
	// else if (keycode == W_KEY_CONST)
	// 	ray_move_up(&data->ray, data->map);
	// else if (keycode == S_KEY_CONST)
	// 	ray_move_down(&data->ray, data->map);
	// else if (keycode == LEFT_KEY_CONST)
	// 	ray_rotate_left(&data->ray);
	// else if (keycode == RIGHT_KEY_CONST)
	// 	ray_rotate_right(&data->ray);
	// else if (keycode == ESC_KEY_CONST)
	// 	handle_hook_close(data);
	// if (DEBUG_INFO)
	// 	debug_ray(&data->ray);
	// return (EXIT_SUCCESS);
	if (keycode == XK_Escape)
		handle_hook_close(data);
	if (keycode == XK_Left)
		data->player.rotate -= 1;
	if (keycode == XK_Right)
		data->player.rotate += 1;
	if (keycode == XK_w)
		data->player.move_y = 1;
	if (keycode == XK_a)
		data->player.move_x = -1;
	if (keycode == XK_s)
		data->player.move_y = -1;
	if (keycode == XK_d)
		data->player.move_x = 1;
	if (DEBUG_INFO)
		debug_ray(&data->ray);
	return (0);
}
//TODO:L Ver se precisa deste método mesmo... o q q ele faz de diferente
static int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		handle_hook_close(data);
	if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (key == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

void	handles_all_hooks(t_data *data)
{
	mlx_hook(data->view.win, 17, 1L << 17, handle_hook_close, data);
	mlx_hook(data->view.win, 2, 1L << 0, handle_hook_key_press, data);
	mlx_hook(data->view.win, KeyRelease, KeyReleaseMask, key_release_handler, data);
	mlx_loop_hook(data->view.mlx, ray_loop, data);
}
