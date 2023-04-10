/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:25:39 by rlins             #+#    #+#             */
/*   Updated: 2023/04/07 20:46:51 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
