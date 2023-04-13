/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:49 by rlins             #+#    #+#             */
/*   Updated: 2023/04/13 17:08:14 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	normalize_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_det.file[i])
	{
		j = 0;
		while (data->map_det.file[i][j])
		{
			if (data->map_det.file[i][j] == '\t')
				data->map_det.file[i][j] = ' ';
			j++;
		}
		i++;
	}
}

/**
 * @brief Will validate the inputs of program.
 * Then, will populate structures by params / handler arguments
 * @param data Data structure
 * @param argv Argument vector
 * @return int value of validations
 */
static int	args_handler(t_data *data, char **argv)
{
	init_map_handler(data, argv[1]);
	normalize_map(data);
	if (file_to_variable(data) != 0)
		return (free_data(data));
	if (valid_map(data) != 0)
		return (free_data(data));
	if (valid_texture(&data->texture_det) != 0)
		return (free_data(data));
	return (0);
}

/**
 * @brief Will initialize the mlx and window
 * structures and will call the setup_textures function
 * to load all textures.
 * @param data Data structure
 */
static void	starting_view(t_data *data)
{
	data->view.mlx = mlx_init();
	if (data->view.mlx == NULL)
	{
		error_msg(ERR_MLX_INIT, 5);
		exit(EXIT_FAILURE);
	}
	setup_textures(data);
	set_player_direction(&data->player);
	data->view.win = mlx_new_window(data->view.mlx, WIDTH, HEIGHT, TITLE);
	if (data->view.win == NULL)
	{
		error_msg(ERR_MLX_WIN, 5);
		exit(EXIT_FAILURE);
	}
	init_img(data, &data->view.screen, WIDTH, HEIGHT);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (error_msg(ERR_ARGS, 1));
	ft_bzero(&data, sizeof(t_data));
	if (args_handler(&data, argv) != 0)
		return (EXIT_FAILURE);
	starting_view(&data);
	starting_game(&data);
	mlx_loop(data.view.mlx);
	return (EXIT_SUCCESS);
}
