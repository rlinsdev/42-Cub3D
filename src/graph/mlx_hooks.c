/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lucas             #+#    #+#             */
/*   Updated: 2023/03/18 05:03:50 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_hook_close(t_data *data)
{
	mlx_destroy_image(data->view.mlx, data->view.screen.img);
	mlx_destroy_image(data->view.mlx, data->view.minimap.img);
	mlx_destroy_window(data->view.mlx, data->view.win);
	mlx_destroy_display(data->view.mlx); // Todo: Comentado p/ compilar
	free_data(data);
	free(data->view.mlx);
	exit(SUCCESS);
}


int	handle_hook_key_press(int keycode, t_data *data)
{
	if (keycode == W_KEY_CONST || keycode == S_KEY_CONST
		|| keycode == A_KEY_CONST || keycode == D_KEY_CONST)
		ray_move(&data->ray, keycode);
	if (keycode == LEFT_KEY_CONST || keycode == RIGHT_KEY_CONST)
		ray_rotate(&data->ray, keycode);
	return (0);
}

int	handle_hook_key(int keycode, t_data *data)
{
	int	drop;

	drop = 0;
	if (keycode == ESC_KEY_CONST)
		handle_hook_close(data);
	handle_hook_key_press(keycode, data);
}
