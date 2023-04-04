/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:24:14 by lucas             #+#    #+#             */
/*   Updated: 2023/04/04 01:22:01 by lucas            ###   ########.fr       */
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

int handle_hook_key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		handle_hook_close(data);
	if (key == XK_w)
		move_player_forward(data);
	if (key == XK_s)
		move_player_backward(data);
	if (key == XK_a)
		move_player_left(data);
	if (key == XK_d)
		move_player_right(data);

	if (key == XK_Left)
		rotate_player_left(data);
	if (key == XK_Right)
		rotate_player_rigth(data);
	return (0);
}

void	handles_all_hooks(t_data *data)
{
	mlx_hook(data->view.win, 17, 1L << 17, handle_hook_close, data);
	mlx_hook(data->view.win, 2, 1L << 0, handle_hook_key_press, data);
	mlx_loop_hook(data->view.mlx, render_images, data);
}
