/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:49 by rlins             #+#    #+#             */
/*   Updated: 2023/03/10 23:14:48 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	args_handler(t_data *data, char **argv);

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->player.pos_x = 22;
	data->player.pos_y = 12;
	data->player.dir_x = -1;
	data->player.plane_y = 0.66;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (error_msg(ERR_ARGS, 1));
	init_data(&data);
	create_graphic(&data);
	if (args_handler(&data, argv) != 0)
		return (EXIT_FAILURE);
	mlx_loop(data.view.mlx);
	return (EXIT_SUCCESS);
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
	if (val_cub_file(argv[1]) == false)
		return (error_msg(ERR_CUB, 4));
	init_map_handler(data, argv[1]);
	if (file_to_variable(data) == EXIT_FAILURE)
		return (free_data(data));
}
