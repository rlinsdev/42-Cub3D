/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:25:39 by rlins             #+#    #+#             */
/*   Updated: 2023/03/30 18:00:28 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	exit_and_free(t_data *data, int s_code)
{
	if (!data)
		exit(s_code);
	if (data->view.win && data->view.mlx)
		mlx_destroy_window(data->view.mlx, data->view.win);
	if (data->view.mlx)
	{
		mlx_destroy_display(data->view.mlx);
		mlx_loop_end(data->view.mlx);
		free(data->view.mlx);
	}
	free_data(data);
	exit(s_code);
}

void	exit_cube(t_data *data, int exit_code)
{
	free_data(data);
	exit(exit_code);
}
