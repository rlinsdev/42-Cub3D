/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lucas             #+#    #+#             */
/*   Updated: 2023/03/30 22:07:19 by rlins            ###   ########.fr       */
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

/**
 * @brief Handle all key press used in game.
 * @param keycode Key code pressed
 * @param data Data structure
 * @return int
 */
int	handle_hook_key_press(int keycode, t_data *data)
{
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
		debug(data);
	return (0);
}

/**
 * @brief Handle the Key Up / key release action. When activated, the player
 * stop to move. Without this, the player keep going
 * @param key Key released
 * @param data Data Structure
 * @return int
 */
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
