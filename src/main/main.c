/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:49 by rlins             #+#    #+#             */
/*   Updated: 2023/03/10 22:06:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	args_handler(t_data *data, char **argv);

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_data(data);
	free(data->mlx);
	exit(SUCCESS);
}

void	init_graphic(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	mlx_hook(data->win, 17, 0, handle_close, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (error_msg(ERR_ARGS, 1));
	ft_bzero(&data, sizeof(t_data));
	init_graphic(&data);
	if (args_handler(&data, argv) != 0)
		return (EXIT_FAILURE);
	mlx_loop(data.mlx);
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
