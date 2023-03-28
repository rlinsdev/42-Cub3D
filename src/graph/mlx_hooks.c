/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lucas             #+#    #+#             */
/*   Updated: 2023/03/28 02:01:23 by lucas            ###   ########.fr       */
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

int	handle_hook_key_press(int keycode, t_data *data)
{
	if (keycode == A_KEY_CONST)
		ray_move_left(&data->ray, data->map);
	else if (keycode == D_KEY_CONST)
		ray_move_right(&data->ray, data->map);
	else if (keycode == W_KEY_CONST)
		ray_move_up(&data->ray, data->map);
	else if (keycode == S_KEY_CONST)
		ray_move_down(&data->ray, data->map);
	else if (keycode == LEFT_KEY_CONST)
		ray_rotate_left(&data->ray);
	else if (keycode == RIGHT_KEY_CONST)
		ray_rotate_right(&data->ray);
	else if (keycode == ESC_KEY_CONST)
		handle_hook_close(data);
	return (EXIT_SUCCESS);
}

void	handles_all_hooks(t_data *data)
{
	mlx_hook(data->view.win, 17, 1L << 17, handle_hook_close, data);
	mlx_hook(data->view.win, 2, 1L << 0, handle_hook_key_press, data);
	mlx_loop_hook(data->view.mlx, ray_loop, data);
}
