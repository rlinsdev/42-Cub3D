/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lucas             #+#    #+#             */
/*   Updated: 2023/03/15 00:56:59 by lucas            ###   ########.fr       */
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

int handle_hook_key(int keycode, t_data *data)
{
	if (keycode == ESC_KEY_CONST)
		handle_hook_close(data);
	return (SUCCESS);
}

// int handle_hook_resize( t_data *data)
// {
// 	int pos_mouse_x;
// 	int pos_mouse_y;

// 	printf("Resize\n");
// 	mlx_destroy_image(data->view.mlx, data->view.screen.img);
// 	mlx_mouse_get_pos(data->view.mlx, data->view.win, &pos_mouse_x, &pos_mouse_y);
// 	if (pos_mouse_x > 0 && pos_mouse_y > 0)
// 	{
// 		data->view.screen_width = pos_mouse_x;
// 		data->view.screen_height = pos_mouse_y;
// 	}
// 	data->view.screen.img = mlx_new_image(data->view.mlx, data->view.screen_width, data->view.screen_height);
// 	data->view.screen.addr = ft_mlx_get_addr(&data->view.screen);
// 	return (SUCCESS);
// }
