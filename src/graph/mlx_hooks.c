/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lucas             #+#    #+#             */
/*   Updated: 2023/03/11 13:19:44 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_hook_close(t_data *data)
{
	mlx_destroy_image(data->view.mlx, data->view.screen.img);
	mlx_destroy_image(data->view.mlx, data->view.minimap.img);
	mlx_destroy_window(data->view.mlx, data->view.win);
	// mlx_destroy_display(data->view.mlx); // Todo: Comentado p/ compilar

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

